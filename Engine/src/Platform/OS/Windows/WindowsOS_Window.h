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
		u32 GetWidth() const override { return m_data.width; }
		u32 GetHeight() const override { return m_data.height; }
		void* GetWindow() const override { return m_window; }
	private:
		GLFWwindow* m_window;
		WindowData m_data;
	};

}