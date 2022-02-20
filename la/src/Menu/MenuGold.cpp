#include "pch.h"
#include "Menu/MenuGold.h"
#include "Menu/MenuArgs.h"
#include "UI/UIBase.h"

namespace LA
{
	template<typename T>
	constexpr T GetGold(T market, double ratio) noexcept
	{
		return static_cast<T>(static_cast<double>(market) * ratio);
	}


	void MenuGold::Render(const Ref<MenuArgs>& args)
	{
		uint32_t marketValue = args->NextOne<uint32_t>();
		if (args->Check())
			return;

		double ratio = 1.0 / .238;
		double wholeRatio = floor(ratio);
		uint32_t per10 = GetGold<uint32_t>(marketValue, ratio);
		uint32_t wholePer10 = GetGold<uint32_t>(marketValue, wholeRatio);

		UIBase::DrawMenuTitle("-- Gold");
		UIBase::DrawFormat("% = %% (%% @ whole units)", "10 EUR", per10, 'g', wholePer10, 'g');
		UIBase::DrawFormat("Market Value: %%", marketValue, 'g');
	}
}