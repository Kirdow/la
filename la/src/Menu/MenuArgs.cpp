#include "pch.h"
#include "Menu/MenuArgs.h"
#include "UI/Format.h"
#include "UI/UIBase.h"

namespace LA
{
	MenuArgs::MenuArgs(const std::string& label, const std::string& args)
		: m_Label(label), m_RawArgs(args), m_Args(args) {}
	MenuArgs::MenuArgs(const MenuArgs& other)
		: m_Label(other.m_Label), m_RawArgs(other.m_RawArgs), m_Args(other.m_RawArgs) {}
	
	const std::string& MenuArgs::FullLine() const
	{
		return m_RawArgs;
	}

	std::string MenuArgs::NextLine()
	{
		return Utils::ReadLine(m_Args);
	}

	bool MenuArgs::Empty() const
	{
		return m_RawArgs.empty();
	}

	bool MenuArgs::Done() const
	{
		return !m_Changed;
	}

	bool MenuArgs::Check() const
	{
		if (m_Changed)
			return false;

		UIBase::DrawFormat("%", "Not enough args!");
		return true;
	}
}