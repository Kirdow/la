#pragma once

#include "Menu/MenuArgs.h"

namespace LA
{
	enum class MenuType
	{
		Gold,
		Mins
	};

	class Menu
	{
	public:
		Menu(const std::string& title, const std::string& desc);
		virtual ~Menu() {}

		inline const std::string& GetTitle() const { return m_Title; }
		inline const std::string& GetDesc() const { return m_Desc; }
		inline bool HasDesc() const { return !m_Desc.empty(); }

		virtual void Render(const Ref<MenuArgs>&) = 0;
		virtual bool Enabled() const { return true; }

		static Ref<Menu> CreateMenu(MenuType type);
	protected:
		std::string m_Title;
		std::string m_Desc;
	};
}