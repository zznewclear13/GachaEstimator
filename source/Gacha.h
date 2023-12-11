#pragma once

#include "GachaOptions.h"
#include "GachaResult.h"

#include <random>

namespace Gacha
{
	GachaResult getResult(const GachaOptions& gachaOptions, std::mt19937& mt);
	void GachaMainLoop(const GachaOptions& gachaOptions);
}
