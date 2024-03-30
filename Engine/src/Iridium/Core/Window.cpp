#include "Window.h"
#include "GLFW/glfw3.h"
#include "Platform/OS/Windows/WindowsOS_Window.h"
namespace Ird {
	std::unique_ptr<Window> Window::IRDCreateWindow() {
		return std::make_unique<WindowsOS_Window>("Editor", 800, 800, false);
	}
}
