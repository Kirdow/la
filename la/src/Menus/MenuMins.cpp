#include "pch.h"
#include "MenuMins.h"

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

	void MenuMins(std::stringstream& args)
	{
		uint32_t input;
		args >> input;

		auto [hours, minutes] = GetPlayTime(input);

		std::cout << "-- Mins\n";
		std::cout << "Total Minutes: " << input << "m\n";
		std::cout << "Playtime: " << hours << ":" << minutes << "\n";
	}
}