#include "Application.h"
#include "Log.h"

namespace Ird {
	Application::Application(){
		m_window = Window::IRDCreateWindow();
		m_running = true;
		Log::Init();
	}
	Application::~Application(){
		Log::Shutdown();
	}
	bool Application::IsRunning() {
		return m_window->IsRunning();
	}

	void Application::Run() {
		while (m_running) {
			m_window->OnUpdate();
			m_running = m_window->IsRunning();
		}
	}

}
