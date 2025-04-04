#include "irpch.h"
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Platform/OS/Windows/WindowsOS_Window.h"
namespace Ird {
	Window* Window::IRDCreateWindow() {
		return new WindowsOS_Window(WindowData("Editor", 800, 800, false));
	}
}
