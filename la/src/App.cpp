#include "pch.h"
#include "App.h"

#include "Menu.h"
#include "Menus/Menus.h"
#include "MenuArgs.h"
#include "Format.h"

#include "Flags.h"

namespace LA
{
	static void ExitCallback(const Ref<MenuArgs>&);

	void App::Init()
	{
		m_Running = true;
		m_Scene = CreateRef<MenuScene>();

		m_Scene->CreateMenu("gold", "gold <amount:i>", MenuGold);
		m_Scene->CreateMenu("mins", "mins <minutes:i>", MenuMins);

		m_Scene->CreateMenu("exit", "", ExitCallback);
	}

	void App::Run()
	{
		bool _cls = !CheckFlag(LAFlags_NoCLS);

		while (m_Running)
		{
			m_Scene->DrawMenu();

			std::cout << FormatColor::FBBlue << "Input: " << BaseStyle;

			auto args = Next();

			if (_cls)
				ClearScreen();

			auto& menuitem = m_Scene->Get(args->GetLabel());
			if (menuitem && menuitem->Render)
			{
				if (!_cls)
					std::cout << RNL;
				menuitem->Render(args);
				std::cout << RNL;
			}
			else
			{
				std::cout << MENU_BG << "Invalid menu {" << MENU_FG << args->GetLabel() << MENU_BG << '}' << BaseStyle << RNL;
			}
		}
	}

	void App::Stop()
	{
		m_Running = false;
	}

	Ref<MenuArgs> App::Next()
	{
		std::string menu = Utils::ReadOne<std::string>();
		std::string input = Utils::ReadLine();

		return MenuArgs::Create(menu, input);
	}

	static void ExitCallback(const Ref<MenuArgs>&)
	{
		App::Get()->Stop();
	}

	static App* s_Instance = nullptr;
	App* App::Get()
	{
		if (s_Instance)
			return s_Instance;

		s_Instance = new App;
		if (s_Instance)
			s_Instance->Init();

		return s_Instance;
	}

	void App::Destroy()
	{
		if (!s_Instance)
			return;

		delete s_Instance;
	}
}