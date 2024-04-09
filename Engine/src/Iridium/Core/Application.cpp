#include "irpch.h"
#include "Application.h"
#include "Time.h"
#include "Iridium/Core/Log.h"
#include "Iridium//Event/Event.h"

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
			auto ev = Queue::GetNextEvent();
			switch (ev->type) {
				case EVENT_TYPE::_None:
				{
					break;
				}
				case EVENT_TYPE::_KeyPressed:
				{
					IRD_CORE_INFO("Event key pressed with key code: {}", ev->data.keyPress.keyCode);
				}
				case EVENT_TYPE::_KeyReleased:
				{
					IRD_CORE_INFO("Event key released with key code: {}", ev->data.keyRelease.keyCode);
				}
				ev->handled = true;
			}
			m_running = m_window->IsRunning();
		}
	}

}
 