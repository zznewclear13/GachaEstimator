#pragma once

namespace Gacha
{
    class GachaResult
    {
    public:
        int m_SSRCount;
        int m_PityCount;
        int m_TotalPulls;

    public:
        void print() const;
    };
}
