#include "irpch.h"
#include "Application.h"
#include "Time.h"
#include "Iridium/Core/Log.h"
#include "Iridium/Event/Event.h"
#include <thread>
#include <chrono>
#include <windows.h>

namespace Ird {
	Application::Application(){
		m_window = Window::IRDCreateWindow();
		m_running = true;
		//Queue::init();
	}
	Application::~Application(){
		delete m_window;
	}
	bool Application::IsRunning() {
		return m_window->IsRunning();
	}

	void Application::Run() {	
		while (m_running) {
			m_window->OnUpdate();
			++TickCount;
			Event* ev = Queue::GetNextEvent();
			if (ev->type == _KeyReleased) {
				IRD_CORE_INFO("Event key released with key code: {}", ev->data.keyRelease.keyCode);
				Queue::ResetEvent(ev);
			}
			else if (ev->type == _KeyPressed) {
				IRD_CORE_INFO("Event key pressed with key code: {}", ev->data.keyPress.keyCode);
				Queue::ResetEvent(ev);
			}
			//IRD_CORE_INFO("Tail is currently: {}, and Head is: {} ", Queue::tail, Queue::head);
			m_running = m_window->IsRunning();
		}
		/*while (m_running) {
			++TickCount;
			for (int j = 0; j < 100; j++) {
				IRD_CORE_INFO("J is {}", j);
				if (j % 3 == 0) {
					Queue::AddKeyPressEvent(4, false);
					IRD_CORE_INFO("Event added");
				}
				Event* ev = Queue::GetNextEvent();

				for (int i = 0; i < 255; i++) {
					std::cout << Queue::evQueue[i].type;
				}
				std::cout << "" << std::endl;

				if (ev->type == _KeyReleased) {
					IRD_CORE_INFO("Event key released with key code: {}", ev->data.keyRelease.keyCode);
					Queue::ResetEvent(ev);
				}
				else if (ev->type == _KeyPressed) {
					IRD_CORE_INFO("Event key pressed with key code: {}", ev->data.keyPress.keyCode);
					Queue::ResetEvent(ev);
				}
				IRD_CORE_INFO("Tail is currently: {}, and Head is: {} ", Queue::tail, Queue::head);

				std::cin.get();
			}
		}*/
	}

}
 