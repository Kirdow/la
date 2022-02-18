#include "pch.h"
#include "Menu.h"
#include "Menus/MenuBase.h"

namespace LA
{
	bool MenuScene::CreateMenu(const std::string& title, const std::string& desc, MenuRenderFunc render)
	{
		if (m_Menus.find(title) != m_Menus.end())
			return false;

		Ref<MenuType> ref = CreateRef<MenuType>(title, desc, render);
		m_Menus[title] = ref;

		return true;
	}

	void MenuScene::DrawMenu() const
	{
		std::cout << FormatColor::FBCyan << "-- Menu Items" << BaseStyle << RNL;
		for (auto& [name, menu] : m_Menus)
		{
			if (menu->Render)
			{
				std::cout << MENU_FG << menu->Title;
				if (!menu->Desc.empty())
					std::cout << MENU_BG << " | Usage: " << MENU_FG << menu->Desc;
				std::cout << BaseStyle << RNL;
			}
			else
			{
				std::cout << MENU_FG << menu->Title << MENU_BG << " (invalid/disabled)" << BaseStyle << RNL;
			}
		}
	}

	const Ref<MenuType>& MenuScene::Get(const std::string& name) const
	{
		if (m_Menus.find(name) == m_Menus.end())
			return nullptr;

		return m_Menus.at(name);
	}

	Ref<MenuArgs> MenuArgs::Create(const std::string& label, const std::string& args)
	{
		return CreateRef<MenuArgs>(label, args);
	}
}