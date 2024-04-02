#include "WindowsOS_Window.h"

namespace Ird {
	
	WindowsOS_Window::WindowsOS_Window(const std::string& title, uint32_t width, uint32_t height, bool vsync)
		:m_title(title), m_width(width), m_height(height), m_vsync(vsync)
	{
		glfwInit();
		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if(!m_window) {
			// Handle window creation failure
			glfwTerminate();
		}

		glfwSetWindowUserPointer(m_window, this);
		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			//WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			//this->HandleKeyEvent();
		});
		glfwMakeContextCurrent(m_window);

		m_running = true;
	}
	WindowsOS_Window::~WindowsOS_Window() {
		glfwDestroyWindow(m_window);
		glfwTerminate(); 
	}
	void WindowsOS_Window::OnUpdate() {

	}

	bool WindowsOS_Window::IsRunning() {
		glfwPollEvents(); // Process GLFW events
		return !glfwWindowShouldClose(m_window) && m_running;
	}

		
}