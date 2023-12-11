#include "GachaOptions.h"

#include "fmt/format.h"

namespace Gacha
{
	bool GachaOptions::fromParser(const InputParser& parser)
	{
		try
		{
			if (parser.cmdOptionExists("-TotalSims"))
			{
				m_TotalSims = std::stoi(parser.getCmdOption("-TotalSims"));
			}
			if (parser.cmdOptionExists("-MaxPulls"))
			{
				m_MaxPulls = std::stoi(parser.getCmdOption("-MaxPulls"));
			}
			if (parser.cmdOptionExists("-BaseProb"))
			{
				m_BaseProb = std::stod(parser.getCmdOption("-BaseProb"));
			}
			if (parser.cmdOptionExists("-SoftPity"))
			{
				m_SoftPity = std::stoi(parser.getCmdOption("-SoftPity"));
			}
			if (parser.cmdOptionExists("-SoftPityProb"))
			{
				m_SoftPityProb = std::stod(parser.getCmdOption("-SoftPityProb"));
			}
			if (parser.cmdOptionExists("-HardPity"))
			{
				m_HardPity = std::stoi(parser.getCmdOption("-HardPity"));
			}
			if (parser.cmdOptionExists("-HardPityProb"))
			{
				m_HardPityProb = std::stod(parser.getCmdOption("-HardPityProb"));
			}
			if (parser.cmdOptionExists("-EarlyExit"))
			{
				m_EarlyExit = parser.getCmdOption("-EarlyExit") == "True";
			}
			return true;
		}
		catch (const std::exception& e)
		{
			fmt::print("Exception throw while parsing GachaOptions: {}", e.what());
			return false;
		}
	}

	void GachaOptions::print() const
	{
		fmt::print("GachaOptions:\n"
			"\tTotalSims:{}\n"
			"\tMaxPulls:{}\n"
			"\tBaseProb:{:.2f}%\n"
			"\tSoftPity:{}\n"
			"\tSoftPityProb:{:.2f}%\n"
			"\tHardPity:{}\n"
			"\tHardPityProb:{:.2f}%\n"
			"\tEarlyExit:{}\n",
			m_TotalSims, m_MaxPulls, m_BaseProb * 100.0, m_SoftPity, m_SoftPityProb * 100.0, m_HardPity, m_HardPityProb * 100.0, m_EarlyExit
		);
	}


}

