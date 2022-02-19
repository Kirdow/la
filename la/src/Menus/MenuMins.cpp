#include "pch.h"
#include "MenuMins.h"
#include "MenuArgs.h"
#include "UI/UIBase.h"

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

		UIBase::DrawMenuTitle("-- Mins");
		UIBase::DrawFormat("Total Minutes: %dm");
		UIBase::DrawFormat("PlayTime %d%c%d", hours, ':', minutes);
	}
}