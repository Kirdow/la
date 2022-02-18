#include "pch.h"
#include "MenuMins.h"
#include "MenuArgs.h"

namespace LA
{
	static struct PlayTime
	{
		uint32_t Hours;
		uint32_t Minutes;
	};

	static PlayTime GetPlayTime(uint32_t minutes)
	{
		return { minutes / 60, minutes % 60 };
	}

	void MenuMins(const Ref<MenuArgs>& args)
	{
		uint32_t input = args->NextOne<uint32_t>();
		if (args->Check())
			return;

		auto [hours, minutes] = GetPlayTime(input);

		std::cout << FormatColor::FBCyan << "-- Mins" << BaseStyle << RNL;
		std::cout << MENU_BG << "Total Minutes: " << MENU_FG << input << MENU_BG << 'm' << BaseStyle << RNL;
		std::cout << MENU_BG << "Playtime: " << MENU_FG << hours << ':' << minutes << BaseStyle << RNL;
	}
}