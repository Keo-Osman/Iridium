#include "irpch.h"
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Platform/OS/Windows/WindowsOSWindow.h"
namespace Ird {
	Window* Window::IRDCreateWindow() {
		return new WindowsOSWindow(WindowData("Editor", 800, 800, false));
	}
}
