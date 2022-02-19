#include "pch.h"
#include "App.h"

#include "Menu/MenuBase.h"
#include "UI/Format.h"
#include "UI/UIBase.h"

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

		UIBase::SetColor(UIBase::Variable::Title, FormatColor::FBCyan);
		UIBase::SetColor(UIBase::Variable::Input, FormatColor::FBBlue);
		UIBase::SetColor(UIBase::Variable::Foreground, FormatColor::FDWhite);
		UIBase::SetColor(UIBase::Variable::Background, FormatColor::FBBlack);
	}

	void App::Run()
	{
		bool _cls = !CheckFlag(LAFlags_NoCLS);

		while (m_Running)
		{
			m_Scene->DrawMenu();

			UIBase::DrawInput();

			auto args = Next();

			if (_cls)
				ClearScreen();

			auto& menuitem = m_Scene->Get(args->GetLabel());
			if (menuitem && menuitem->Render)
			{
				UIBase::DrawLine(_cls);
				menuitem->Render(args);
				UIBase::DrawLine();
			}
			else
			{
				UIBase::DrawFormat("Invalid menu {%s}", args->GetLabel());
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