#include "GachaResult.h"

#include "fmt/format.h"

namespace Gacha
{
	void GachaResult::print() const
	{
		fmt::print("GachaResult\n"
			"\tSSRCount: {}\n"
			"\tPityCount: {}\n"
			"\tTotalPulls: {}\n",
			m_SSRCount, m_PityCount, m_TotalPulls
		);
	}
}