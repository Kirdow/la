#include "pch.h"
#include "Menu.h"

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
		std::cout << "-- Menu Items\n";
		for (auto& [name, menu] : m_Menus)
		{
			if (menu->Render)
			{
				std::cout << menu->Title;
				if (!menu->Desc.empty())
					std::cout << " | Usage: " << menu->Desc;
				std::cout << "\n";
			}
			else
			{
				std::cout << menu->Title << " (invalid/disabled)\n";
			}
		}
	}

	const Ref<MenuType>& MenuScene::Get(const std::string& name) const
	{
		if (m_Menus.find(name) == m_Menus.end())
			return nullptr;

		return m_Menus.at(name);
	}
}