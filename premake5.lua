workspace "Lilac"
	architecture "x64"
	startproject "SandBox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}



outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lilac"
	location "Lilac"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "llpch.h"
	pchsource "Lilac/src/llpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"LL_PLATFORM_WINDOWS",
			"LL_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/SandBox/\"")
		}

	filter "configurations:Debug"
		defines "LL_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "LL_DEBUG"
		optimize "On"


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Lilac/vendor/spdlog/include",
		"Lilac/src"
	}

	links{
		"Lilac"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"LL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LL_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "LL_DEBUG"
		optimize "On"
