#pragma once
#include "Iridium/Core/Window.h"
#include "GLFW/glfw3.h"
#include <string>
namespace Ird {
	class WindowsOS_Window : public Window {
	public:
		WindowsOS_Window(const std::string& title, uint32_t width, uint32_t height, bool vsync);
		~WindowsOS_Window();
		void OnUpdate() override;
		bool IsRunning() override;
		unsigned int GetWidth() const override { return m_width; }
		unsigned int GetHeight() const override { return m_height; }
		void HandleKeyEvent(int key, int scancode, int action, int mods) const {
			//Dispatch Event here
		}
	private:
		GLFWwindow* m_window;
		bool m_running;
		std::string m_title;
		uint32_t m_width, m_height;
		bool m_vsync;
	};
}