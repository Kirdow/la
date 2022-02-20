#pragma once

#include "Utils/Base.h"
#include "UI/Format.h"

#ifdef LA_DEBUG
	#if defined(LA_PLATFORM_WINDOWS)
		#define LA_DEBUGBREAK() __debugbreak()
	#elif defined(LA_PLATFORM_LINUX)
		#include <signal.h>
		#define LA_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
#else
	#define LA_DEBUGBREAK()
#endif

#define BIT(x) (1 << x)

namespace LA
{
	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename...Args>
	constexpr Ref<T> CreateRef(Args&&...args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename...Args>
	constexpr Scope<T> CreateScope(Args&&...args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}