-- engine/premake5.lua
include "Dependencies.lua"

project "Engine"

    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")
    objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")


    libdirs {"%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/ECS"}

    links {
        "glfw",
        "ECS"
    }
    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs { 
        "src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.spdlog}"
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
        defines { "IRD_PLATFORM_WINDOWS"}
        links { "user32", "gdi32", "shell32","ntdll", "msvcrt" }

    filter "system:linux"
        links { "X11", "pthread", "dl" }