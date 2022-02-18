#include "pch.h"
#include "Flags.h"

namespace LA
{
	static uint32_t s_Flags = 0;

	void SetFlags(LAFlags flags, bool state)
	{
		uint32_t f = static_cast<uint32_t>(flags);

		if (state)
			s_Flags |= f;
		else
			s_Flags &= ~f;

	}

	bool CheckFlag(LAFlags flags)
	{
		uint32_t f = static_cast<uint32_t>(flags);

		return (s_Flags & f) == f;
	}
}