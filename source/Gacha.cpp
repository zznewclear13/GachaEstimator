#include "Gacha.h"

#include "fmt/format.h"
#include "nanothread/nanothread.h"

#include <vector>

namespace Gacha
{
	GachaResult getResult(const GachaOptions& gachaOptions, std::mt19937& mt)
	{
		static std::uniform_real_distribution<double> ran{ 0.0, 1.0 };

		GachaResult result{};
		int currentPity{ 0 };
		double probability{ gachaOptions.m_BaseProb };
		for (size_t i = 0; i < gachaOptions.m_MaxPulls; i++)
		{
			result.m_TotalPulls = i + 1;
			++currentPity;

			if (currentPity >= gachaOptions.m_HardPity)
			{
				if (ran(mt) < gachaOptions.m_HardPityProb)
				{
					++result.m_PityCount;
					++result.m_SSRCount;
					currentPity = 0;
					probability = gachaOptions.m_BaseProb;
					if (gachaOptions.m_EarlyExit) break;
					else continue;
				}
			}

			if (currentPity > gachaOptions.m_SoftPity)
			{
				probability += gachaOptions.m_SoftPityProb;
			}

			if (ran(mt) < probability)
			{
				++result.m_SSRCount;
				currentPity = 0;
				probability = gachaOptions.m_BaseProb;
				if (gachaOptions.m_EarlyExit) break;
				else continue;
			}
		}
		return result;
	}

	void GachaMainLoop(const GachaOptions& gachaOptions)
	{
		uint32_t randomPoolSize{ pool_size() + 1 };
		std::vector<std::mt19937> mts(randomPoolSize);
		for (uint32_t i = 0; i < randomPoolSize; i++)
		{
			mts[i] = std::mt19937{ std::random_device{}() };
		}

		std::vector<GachaResult> results(gachaOptions.m_TotalSims);
		drjit::parallel_for(
			drjit::blocked_range<uint32_t>(0, gachaOptions.m_TotalSims),
			[&](drjit::blocked_range<uint32_t> range)
			{
				for (auto i = range.begin(); i < range.end(); ++i)
				{
					results[i.value] = getResult(gachaOptions, mts[pool_thread_id()]);
				}
			}
		);

		int totalSSRCount{ 0 };
		int totalPityCount{ 0 };
		int totalPulls{ 0 };
		for (const auto& result : results)
		{
			totalSSRCount += result.m_SSRCount;
			totalPityCount += result.m_PityCount;
			totalPulls += result.m_TotalPulls;
		}

		double totalSSR{ static_cast<double>(totalSSRCount) };
		double averageProb{ totalSSR / totalPulls };
		double pityProb{ totalPityCount / totalSSR };
		double averagePulls{ totalPulls / totalSSR };
		fmt::print("平均出货概率AverageProb: {:.2f}%, 平均出货保底概率PityProb: {:.2f}%, 平均出货抽数AveragePulls: {}\n",
					averageProb * 100.0, pityProb * 100.0, averagePulls);
	}
}
