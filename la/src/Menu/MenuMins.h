#pragma once

#include "Menu/Menu.h"

namespace LA
{
	class MenuMins : public Menu
	{
	public:
		MenuMins()
			: Menu("mins", "mins <minutes:i>") {}

		virtual void Render(const Ref<MenuArgs>& args) override;
	};
}