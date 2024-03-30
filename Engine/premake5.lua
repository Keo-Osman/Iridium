-- engine/premake5.lua
include "Dependencies.lua"

project "Engine"

    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.system}__%{cfg.architecture}/%{prj.name}")
    objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.system}__%{cfg.architecture}/%{prj.name}")

    buildoptions { " -pthread " }
    linkoptions { " -pthread " }

    libdirs {"%{wks.location}/lib"}

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
    
    --[[filter "system:windows"
        defines { "IRD_PLATFORM_WINDOWS"}
        links { "user32", "gdi32", "shell32","ntdll", "msvcrt", "libc" }

    filter "system:linux"
        links { "X11", "pthread", "dl" }]]