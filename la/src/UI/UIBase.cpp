#include "pch.h"
#include "UI/UIBase.h"
#include "UI/Format.h"

namespace LA
{
	struct UIBase_Data
	{
		FormatColor C_Background;
		FormatColor C_Foreground;
		FormatColor C_Title;
		FormatColor C_Input;

		UIBase_Data()
			: C_Background(BaseStyle),
			  C_Foreground(BaseStyle),
			  C_Title(BaseStyle),
			  C_Input(BaseStyle)
		{
		}
	};

	static UIBase_Data s_Data;

	void UIBase::DrawMenuTitle(const std::string& titleName)
	{
		std::cout << s_Data.C_Title << titleName << BaseStyle << RNL;
	}

	void UIBase::DrawLine(bool skip)
	{
		if (skip)
			return;

		std::cout << s_Data.C_Background << RNL;
	}

	void UIBase::DrawInput()
	{
		std::cout << s_Data.C_Input << "Input: " << BaseStyle;
	}

	void UIBase::SetColor(Variable var, FormatColor color)
	{
		switch (var)
		{
		case Variable::Title:		s_Data.C_Title = color; break;
		case Variable::Input:		s_Data.C_Input = color; break;
		case Variable::Background:	s_Data.C_Background = color; break;
		case Variable::Foreground:	s_Data.C_Foreground = color; break;
		}
	}

	FormatColor UIBase::GetColor(Variable var)
	{
		switch (var)
		{
		case Variable::Title:		return s_Data.C_Title;
		case Variable::Input:		return s_Data.C_Input;
		case Variable::Background:	return s_Data.C_Background;
		case Variable::Foreground:	return s_Data.C_Foreground;
		}

		return BaseStyle;
	}
}