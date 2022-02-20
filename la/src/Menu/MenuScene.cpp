#include "pch.h"
#include "Menu/MenuScene.h"
#include "Menu/MenuBase.h"
#include "UI/UIBase.h"

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
		UIBase::DrawMenuTitle("-- Menu Items");
		for (auto& [name, menu] : m_Menus)
		{
			if (menu->Render)
			{
				UIBase::DrawFormat(true, "%", menu->Title);
				if (!menu->Desc.empty())
					UIBase::DrawFormat(true, " | Usage: %", menu->Desc);
				UIBase::DrawLine();
			}
			else
			{
				UIBase::DrawFormat("% (invalid/disabled)", menu->Title);
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