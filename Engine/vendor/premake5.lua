project "glfw"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    location "%{prj.name}"
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}")
    objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")
    
    files {
        "%{prj.name}/include/GLFW/glfw3.h",
        "%{prj.name}/include/GLFW/glfw3native.h",
        "%{prj.name}/src/internal.h",
        "%{prj.name}/src/platform.h",
        "%{prj.name}/src/mappings.h",
        "%{prj.name}/src/context.c",
        "%{prj.name}/src/init.c",
        "%{prj.name}/src/input.c",
        "%{prj.name}/src/monitor.c",
        "%{prj.name}/src/platform.c",
        "%{prj.name}/src/vulkan.c",
        "%{prj.name}/src/window.c",
        "%{prj.name}/src/egl_context.c",
        "%{prj.name}/src/osmesa_context.c",
        "%{prj.name}/src/null_platform.h",
        "%{prj.name}/src/null_joystick.h",
        "%{prj.name}/src/null_init.c",
        "%{prj.name}/src/null_monitor.c",
        "%{prj.name}/src/null_window.c",
        "%{prj.name}/src/null_joystick.c",

    }

    filter "system:linux"
        pic "On"

        systemversion "latest"
        staticruntime "On"

        files {
            "%{prj.name}/src/x11_init.c",
            "%{prj.name}/src/x11_monitor.c",
            "%{prj.name}/src/x11_window.c",
            "%{prj.name}/src/xkb_unicode.c",
            "%{prj.name}/src/posix_time.c",
            "%{prj.name}/src/posix_thread.c",
            "%{prj.name}/src/glx_context.c",
            "%{prj.name}/src/egl_context.c",
            "%{prj.name}/src/osmesa_context.c",
            "%{prj.name}/src/linux_joystick.c"
        }

        defines {
            "_GLFW_X11"
        
        }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        files
        {
            "%{prj.name}/src/win32_init.c",
            "%{prj.name}/src/win32_module.c",
            "%{prj.name}/src/win32_joystick.c",
            "%{prj.name}/src/win32_monitor.c",
            "%{prj.name}/src/win32_time.h",
            "%{prj.name}/src/win32_time.c",
            "%{prj.name}/src/win32_thread.h",
            "%{prj.name}/src/win32_thread.c",
            "%{prj.name}/src/win32_window.c",
            "%{prj.name}/src/wgl_context.c",
            "%{prj.name}/src/egl_context.c",
            "%{prj.name}/src/osmesa_context.c"
        }

        defines { 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"

        }
        links { "user32", "gdi32", "shell32", "ntdll" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"




project "ImGui"
    kind "StaticLib"
    language "C"
    location "%{prj.name}"
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}")
    objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.architecture}__%{cfg.system}/%{prj.name}")
    


    files {
		"%{prj.name}/imconfig.h",
		"%{prj.name}/imgui.h",
		"%{prj.name}/imgui.cpp",
		"%{prj.name}/imgui_draw.cpp",
		"%{prj.name}/imgui_internal.h",
		"%{prj.name}/imgui_widgets.cpp",
		"%{prj.name}/imstb_rectpack.h",
		"%{prj.name}/imstb_textedit.h",
		"%{prj.name}/imstb_truetype.h",
		"%{prj.name}/imgui_demo.cpp"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++20"
		staticruntime "On"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++20"
		staticruntime "On"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"