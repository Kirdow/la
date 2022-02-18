#pragma once

#ifndef BIT
#define BIT(x) (1 << x)
#endif

namespace LA
{
	enum LAFlags
	{
		LAFlags_None = 0,
		LAFlags_NoCLS = BIT(0)
	};

	void SetFlags(LAFlags, bool);
	bool CheckFlag(LAFlags);
}