#include "pch.h"
#include "UI/Format.h"

namespace LA
{
	void ClearScreen()
	{
		// TODO: Do this properly
		system("cls");
		std::cout << BaseStyle;
	}

	void ResetStyle()
	{
		std::cout << BaseStyle;
	}

	std::ostream& operator<<(std::ostream& ostr, LA::FormatColor color)
	{
		ostr << static_cast<char>(0x1B) << '[' << static_cast<uint32_t>(color) << 'm';

		return ostr;
	}
}
