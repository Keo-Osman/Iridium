-- editor/premake5.lua
include "Dependencies.lua"
project "Editor"
    kind "ConsoleApp"
    staticruntime "on"
    language "C++"
    cppdialect "C++20"
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")
    objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")

    libdirs {"%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/ECS"}

    includedirs { 
        "src",
        "%{wks.location}/Engine/src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}"
    }
    links { 
        "Engine",
        "glfw",
        "ECS"
    }
    files {
        "src/**.cpp",
        "src/**.h"
    }
    filter "configurations:Dist"
        defines{
            "IRD_DIST"
        }
    filter "system:windows"
        --linkoptions { " /NODEFAULTLIB:library " }
        defines { "IRD_PLATFORM_WINDOWS"}
        links { "user32", "gdi32", "shell32", "ntdll" }

    filter "system:linux"
        links { "X11", "pthread" }
