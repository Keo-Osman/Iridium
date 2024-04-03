#include "WindowsOS_Window.h"

namespace Ird {
	
	WindowsOS_Window::WindowsOS_Window(const WindowData& data)
		:m_data(data)
	{
		glfwInit();
		m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
		if(!m_window) {
			// Handle window creation failure
			glfwTerminate();
		}

		glfwSetWindowUserPointer(m_window, this);

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mode){
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
			{
				/*case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, true);
					data.EventCallback(event);
					break;
				}*/
			}
        });
		glfwMakeContextCurrent(m_window);
		m_running = true;
	}
	WindowsOS_Window::~WindowsOS_Window() {
		glfwDestroyWindow(m_window);
		glfwTerminate(); 
		m_running = false;
	}
	void WindowsOS_Window::OnUpdate() {

	}

	bool WindowsOS_Window::IsRunning() {
		glfwPollEvents(); // Process GLFW events
		return !glfwWindowShouldClose(m_window) && m_running;
	}

		
}