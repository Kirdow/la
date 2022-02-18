#include "pch.h"
#include "MenuGold.h"

namespace LA
{
	template<typename T>
	constexpr T GetGold(T market, double ratio) noexcept
	{
		return static_cast<T>(static_cast<double>(market) * ratio);
	}

	void MenuGold(std::stringstream& args)
	{
		uint32_t marketValue;
		args >> marketValue;

		double ratio = 1.0 / .238;
		double wholeRatio = floor(ratio);
		uint32_t per10 = GetGold<uint32_t>(marketValue, ratio);
		uint32_t wholePer10 = GetGold<uint32_t>(marketValue, wholeRatio);

		std::cout << "-- Gold\n";
		std::cout << "10 EUR = " << per10 << "g (" << wholePer10 << "g @ whole units)\n";
		std::cout << "Market Value: " << marketValue << "g\n";
	}
}