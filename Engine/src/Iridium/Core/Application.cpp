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
			evQueue::Handle ev = evQueue::GetNextEvents();
			for(int i = 0; i < ev.numOfEvents; i++){
				IRD_CORE_INFO("Event with type: {}", evQueue::queue[ev.head].type);
				switch(evQueue::queue[ev.head].type){

				case EVENT_TYPE::KeyPressed:
					IRD_CORE_INFO("Event key released with key code: {}", evQueue::queue[ev.head].data.keyRelease.keyCode);
					evQueue::queue[ev.head].handled = true;
					break;
				case EVENT_TYPE::KeyReleased:
					IRD_CORE_INFO("Event key pressed with key code: {}", evQueue::queue[ev.head].data.keyPress.keyCode);
					evQueue::queue[ev.head].handled = true;
					break;

				case EVENT_TYPE::MouseButtonPressed:
					IRD_CORE_INFO("Event mouse button pressed with key code: {}", evQueue::queue[ev.head].data.mouseButton.mouseCode);
					evQueue::queue[ev.head].handled = true;
					break;

				case EVENT_TYPE::MouseButtonReleased:
					IRD_CORE_INFO("Event mouse button released with key code: {}", evQueue::queue[ev.head].data.mouseButton.mouseCode);
					evQueue::queue[ev.head].handled = true;
					break;

				case EVENT_TYPE::MouseMoved:
					IRD_CORE_INFO("Event mouse moved to: {}, {}", evQueue::queue[ev.head].data.mousePos.x, evQueue::queue[ev.head].data.mousePos.y);
					evQueue::queue[ev.head].handled = true;
					break;

				case EVENT_TYPE::MouseScrolled:
					IRD_CORE_INFO("Event mouse scrolled with offest: {}, {}", evQueue::queue[ev.head].data.mousePos.x, evQueue::queue[ev.head].data.mousePos.y);
					evQueue::queue[ev.head].handled = true;
					break;

				default:
        			break;
				}
				ev.head++;
			}
		}
	}

}
 