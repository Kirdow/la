project "la"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "src/pch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "LA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LA_DIST"
		runtime "Release"
		optimize "on"
