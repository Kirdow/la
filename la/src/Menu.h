#pragma once

namespace LA
{
	typedef void(*MenuRenderFunc)(std::stringstream&);

	struct MenuType
	{
		std::string Title;
		std::string Desc;
		MenuRenderFunc Render;

		MenuType()
			: Title(""), Desc(""), Render(nullptr) {}
		MenuType(const std::string& title, const std::string& desc, MenuRenderFunc render)
			: Title(title), Desc(desc), Render(render) {}
		MenuType(const MenuType& other)
			: Title(other.Title), Desc(other.Desc), Render(other.Render) {}
	};

	class MenuScene
	{
	public:
		MenuScene() = default;

		bool CreateMenu(const std::string& title, const std::string& desc, MenuRenderFunc render);
		void DrawMenu() const;

		const Ref<MenuType>& Get(const std::string& name) const;
	private:
		std::unordered_map<std::string, Ref<MenuType>> m_Menus;
	};
}