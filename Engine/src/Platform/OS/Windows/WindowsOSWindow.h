#pragma once
#include "irpch.h"
#include "Iridium/Core/Window.h"
#include "GLFW/glfw3.h"

namespace Ird {
	class WindowsOSWindow : public Window {
	public:
		WindowsOSWindow(const WindowData& data);
		~WindowsOSWindow();
		bool OnUpdate() override;
		u32 getWidth() const override { return m_data.width; }
		u32 getHeight() const override { return m_data.height; }
		void* GetWindow() const override { return m_window; }
	private:
		GLFWwindow* m_window;
		WindowData m_data;
	};

}