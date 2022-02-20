#pragma once

#include "Menu/Menu.h"

namespace LA
{
	class MenuGold : public Menu
	{
	public:
		MenuGold()
			: Menu("gold", "gold <amount:i>") {}

		virtual void Render(const Ref<MenuArgs>& args) override;
	};
}