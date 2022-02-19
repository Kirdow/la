#pragma once

#include "Format.h"

namespace LA
{
#define UISTR(s) std::string(s)

	class UIBase
	{
	public:
		enum class Variable
		{
			Title,
			Background,
			Foreground,
			Input
		};

	public:
		static void DrawMenuTitle(const std::string& titleName);
		static void DrawFormat(bool skipNewLine, const char* fmt, ...);
		static void DrawFormat(const char* fmt, ...);

		static void DrawLine(bool skip = false);
		static void DrawInput();

		static void SetColor(Variable var, FormatColor color);
		static FormatColor GetColor(Variable var);
	private:
		static void DrawFormatImpl(bool skipNewLine, const char* fmt, va_list args);
	};
}