#include "pch.h"
#include "MenuGold.h"
#include "MenuArgs.h"

namespace LA
{
	template<typename T>
	constexpr T GetGold(T market, double ratio) noexcept
	{
		return static_cast<T>(static_cast<double>(market) * ratio);
	}

	void MenuGold(const Ref<MenuArgs>& args)
	{
		uint32_t marketValue = args->NextOne<uint32_t>();
		if (args->Check())
			return;

		double ratio = 1.0 / .238;
		double wholeRatio = floor(ratio);
		uint32_t per10 = GetGold<uint32_t>(marketValue, ratio);
		uint32_t wholePer10 = GetGold<uint32_t>(marketValue, wholeRatio);

		std::cout << FormatColor::FBCyan << "-- Gold" << BaseStyle << RNL;
		std::cout << MENU_FG << "10 EUR" << MENU_BG << " = " << MENU_FG << per10 << 'g'
			<< MENU_BG << " (" << MENU_FG << wholePer10 << 'g' << MENU_BG << " @ whole units)" << BaseStyle << RNL;
		std::cout << MENU_BG << "Market Value: " << MENU_FG << marketValue << 'g' << BaseStyle << RNL;
	}
}