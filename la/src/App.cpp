#include "pch.h"
#include "App.h"

#include "StringUtils.h"

#include "Menu.h"
#include "Menus/Menus.h"

namespace LA
{
	static void ExitCallback(std::stringstream&);

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
		while (m_Running)
		{
			m_Scene->DrawMenu();
			std::cout << "Input: ";

			std::string menu;
			std::cin >> menu;

			std::string input;
			std::getline(std::cin, input);

			std::stringstream args(Utils::TrimCopy(input));

			auto& menuitem = m_Scene->Get(menu);
			if (menuitem && menuitem->Render)
			{
				std::cout << "\n";
				menuitem->Render(args);
				std::cout << "\n";
			}
			else
			{
				std::cout << "\nInvalid menu {" << menu << "}\n";
			}
		}
	}

	void App::Stop()
	{
		m_Running = false;
	}

	static void ExitCallback(std::stringstream&)
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