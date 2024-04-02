#include "Application.h"
#include "Time.h"

namespace Ird {
	Application::Application(){
		m_window = Window::IRDCreateWindow();
		m_running = true;
	}
	Application::~Application(){
		delete m_window;
	}
	bool Application::IsRunning() {
		return m_window->IsRunning();
	}

	void Application::Run() {
		while (m_running) {
			++TickCount;
			m_window->OnUpdate();
			m_running = m_window->IsRunning();
		}
	}

}
 