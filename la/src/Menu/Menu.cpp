#include "pch.h"
#include "Menu/Menu.h"

#include "Menu/MenuGold.h"
#include "Menu/MenuMins.h"

namespace LA
{
	Menu::Menu(const std::string& title, const std::string& desc)
		: m_Title(title), m_Desc(desc) {}

	Ref<Menu> Menu::CreateMenu(MenuType type)
	{
		switch (type)
		{
		case MenuType::Gold:		return CreateRef<MenuGold>();
		case MenuType::Mins:		return CreateRef<MenuMins>();
		}

		LA_DEBUGBREAK();
		return nullptr;
	}
}