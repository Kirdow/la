#pragma once

#define BaseStyle ::LA::FormatColor::Default
#define RNL '\n'

namespace LA
{
	enum class FormatColor
	{
		Default = 0,
		Bold = 1,
		Underline = 4,
		Negative = 7,
		NoBold = 22,
		Positive = 27,
		FDBlack = 30,
		FDRed,
		FDGreen,
		FDYellow,
		FDBlue,
		FDMagenta,
		FDCyan,
		FDWhite,
		FDExtended,
		FDDefault,
		BDBlack,
		BDRed,
		BDGreen,
		BDYellow,
		BDBlue,
		BDMagenta,
		BDCyan,
		BDWhite,
		BDExtended,
		BDDefault,
		FBBlack = 90,
		FBRed,
		FBGreen,
		FBYellow,
		FBBlue,
		FBMagenta,
		FBCyan,
		FBWhite,
		BBBlack = 100,
		BBRed,
		BBGreen,
		BBYellow,
		BBBlue,
		BBMagenta,
		BBCyan,
		BBWhite
	};

	void ClearScreen();
	void ResetStyle();
	std::ostream& operator<<(std::ostream& ostr, LA::FormatColor color);
}
