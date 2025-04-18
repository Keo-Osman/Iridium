#include "irpch.h"
#include "WindowsOS_Window.h"
#include "Iridium/Event/Event.h"
#include "Iridium/Core/Log.h"

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

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			evQueue::AddWindowResizeEvent(width, height);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			evQueue::AddWindowCloseEvent();
		});


		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mode){
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch (action)
			{
				case GLFW_PRESS:
				{
					evQueue::AddKeyPressEvent(key, false);
					break;
				}
				case GLFW_RELEASE:
				{
					evQueue::AddKeyReleaseEvent(key);
					break;
				}
				case GLFW_REPEAT:
				{
					evQueue::AddKeyPressEvent(key, true);
					break;
				}
			}
        });

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					evQueue::AddMousePressEvent(button);
					break;
				}
				case GLFW_RELEASE:
				{
					evQueue::AddMouseReleaseEvent(button);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			evQueue::AddMouseScrollEvent(xOffset, yOffset);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			evQueue::AddMouseMoveEvent(xPos, yPos);
		});

		glfwMakeContextCurrent(m_window);
	}
	
	WindowsOS_Window::~WindowsOS_Window() {
		glfwDestroyWindow(m_window);
		glfwTerminate(); 
	}
	
	bool WindowsOS_Window::OnUpdate() {
		glfwPollEvents();
		return !glfwWindowShouldClose(m_window);
	}

	
		
}