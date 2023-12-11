#pragma once

#include "support/InputParser.h"

namespace Gacha
{
	class GachaOptions
	{
	public:
		int m_TotalSims{ 1000 };
		int m_MaxPulls{ 100 };
		double m_BaseProb{ 0.006 };
		int m_SoftPity{ 73 };
		double m_SoftPityProb{ 0.06 };
		int m_HardPity{ 90 };
		double m_HardPityProb{ 1.0 };

		bool m_EarlyExit{ true };

	public:
		bool fromParser(const InputParser& parser);
		void print() const;
	};
}