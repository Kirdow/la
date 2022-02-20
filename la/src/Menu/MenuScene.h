#pragma once

#include "Menu/MenuArgs.h"
#include "Menu/Menu.h"

namespace LA
{
	typedef void(*MenuRenderFunc)(const Ref<MenuArgs>&);

	class MenuScene
	{
	public:
		MenuScene() = default;

		void DrawMenu() const;
		void RegisterMenu(MenuType type);
		void RegisterMenu(const std::string& title, const std::string& desc, MenuRenderFunc);

		const Ref<Menu>& Get(MenuType type) const;
		const Ref<Menu>& Get(const std::string& name) const;
	private:
		std::unordered_map<MenuType, std::string> m_MenuNames;
		std::unordered_map<std::string, Ref<Menu>> m_Menus;
	};
}