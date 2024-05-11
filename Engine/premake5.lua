include "Dependencies.lua"

project "Engine"
    staticruntime "on"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")
    objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")


    libdirs {"%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/ECS"}

    links {
        "glfw",
        "ECS",
        "ImGui"
    }
    files {
        "src/**.cpp",
        "src/**.h"
    }
    pchheader "irpch.h"
	pchsource "src/irpch.cpp"
    includedirs { 
        "src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.ImGui}",

    }
    
    filter "configurations:Dist"
        defines{
            "IRD_DIST"
        }

    filter "configurations:Release"
        defines{
            "IRD_RELEASE"
        }

    filter "configurations:Debug"
        defines{
            "IRD_DEBUG"
        }
    
    filter "system:windows"
        --linkoptions { " /NODEFAULTLIB:library " }
        defines { "IRD_PLATFORM_WINDOWS", "IRD_WINDOW_GLFW"}
        links { "user32", "gdi32", "shell32","ntdll"}

    filter "system:linux"
        links { "X11", "pthread", "dl" }