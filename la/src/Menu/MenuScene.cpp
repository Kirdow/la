#include "pch.h"
#include "Menu/MenuScene.h"
#include "Menu/Menu.h"
#include "UI/UIBase.h"

namespace LA
{
	class AnonymousMenu : public Menu
	{
	public:
		AnonymousMenu(const std::string& title, const std::string& desc, MenuRenderFunc render)
			: Menu(title, desc), m_RenderFunc(render)
		{}

		virtual void Render(const Ref<MenuArgs>& args) override
		{
			if (m_RenderFunc)
				m_RenderFunc(args);
		}

		virtual bool Enabled() const override
		{
			return m_RenderFunc;
		}

	private:
		MenuRenderFunc m_RenderFunc;
	};

	static void DrawMenuEntry(const Ref<Menu>& menu)
	{
		if (menu->Enabled())
		{
			UIBase::DrawFormat(true, "%", menu->GetTitle());
			if (menu->HasDesc())
				UIBase::DrawFormat(true, " | Usage: %", menu->GetDesc());
			UIBase::DrawLine();
		}
		else
		{
			UIBase::DrawFormat("% (disabled/invalid)", menu->GetTitle());
		}
	}

	void MenuScene::DrawMenu() const
	{
		Ref<Menu> exitEntry = nullptr;
		UIBase::DrawMenuTitle("-- Menu Items");
		for (auto& [name, menu] : m_Menus)
		{
			if (name == "exit")
			{
				exitEntry = menu;
				continue;
			}

			DrawMenuEntry(menu);
		}
		
		if (exitEntry)
			DrawMenuEntry(exitEntry);
	}

	void MenuScene::RegisterMenu(MenuType type)
	{
		auto ref = Menu::CreateMenu(type);

		auto& title = ref->GetTitle();
		m_Menus[title] = ref;
		m_MenuNames[type] = title;
	}

	void MenuScene::RegisterMenu(const std::string& title, const std::string& desc, MenuRenderFunc render)
	{
		if (m_Menus.find(title) != m_Menus.end())
			return;

		Ref<Menu> ref = CreateRef<AnonymousMenu>(title, desc, render);
		m_Menus[title] = ref;
	}

	const Ref<Menu>& MenuScene::Get(const std::string& name) const
	{
		if (m_Menus.find(name) == m_Menus.end())
			return nullptr;

		return m_Menus.at(name);
	}

	const Ref<Menu>& MenuScene::Get(MenuType type) const
	{
		if (m_MenuNames.find(type) == m_MenuNames.end())
			return nullptr;

		auto name = m_MenuNames.at(type);
		return Get(name);
	}

	Ref<MenuArgs> MenuArgs::Create(const std::string& label, const std::string& args)
	{
		return CreateRef<MenuArgs>(label, args);
	}
}