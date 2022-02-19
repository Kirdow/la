#pragma once

#include "Format.h"

namespace LA
{
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

		static void DrawFormat(bool skipNewLine, const char* fmt)
		{
			std::cout << GetColor(Variable::Background) << fmt;

			if (!skipNewLine)
				std::cout << RNL;
		}

		template<typename T, typename...Args>
		static void DrawFormat(bool skipNewLine, const char* fmt, T arg, Args... args)
		{
			std::cout << GetColor(Variable::Background);

			for (;*fmt != '\0'; ++fmt)
			{
				if (*fmt == '%')
				{
					std::cout << GetColor(Variable::Foreground) << arg;
					DrawFormat(skipNewLine, fmt + 1, args...);
					return;
				}
				std::cout << *fmt;
			}

			if (!skipNewLine)
				std::cout << RNL;
		}

		template<typename...Args>
		static void DrawFormat(const char* fmt, Args... args)
		{
			DrawFormat(false, fmt, args...);
		}

		static void DrawLine(bool skip = false);
		static void DrawInput();

		static void SetColor(Variable var, FormatColor color);
		static FormatColor GetColor(Variable var);
	};
}