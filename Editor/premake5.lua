-- editor/premake5.lua
include "Dependencies.lua"
project "Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.system}__%{cfg.architecture}/%{prj.name}")
    objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.system}__%{cfg.architecture}/%{prj.name}")



    buildoptions { " -pthread " }
    linkoptions { " -pthread " }

    libdirs {"%{wks.location}/lib"}

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
        defines { "IRD_PLATFORM_WINDOWS"}
        links { "user32", "gdi32", "shell32" }

    filter "system:linux"
        links { "X11", "pthread" }
