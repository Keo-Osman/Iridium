#pragma once
#include "irpch.h"
#include "Iridium/Core/Window.h"
#include "GLFW/glfw3.h"

namespace Ird {
	class WindowsOS_Window : public Window {
	public:
		WindowsOS_Window(const WindowData& data);
		~WindowsOS_Window();
		bool OnUpdate() override;
		bool IsRunning() override;
		unsigned int GetWidth() const override { return m_data.width; }
		unsigned int GetHeight() const override { return m_data.height; }
	private:
		GLFWwindow* m_window;
		bool m_running;
		WindowData m_data;
	};

}