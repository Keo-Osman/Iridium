#include "irpch.h"
#include "Application.h"
#include "Iridium/Core/Time.h"
#include "Iridium/Core/Log.h"
#include "Iridium/Core/Input.h"


namespace Ird {
	Application* Application::s_instance = nullptr;
	Application::Application(){
		m_window = Window::IRDCreateWindow();
		m_running = true;
		s_instance = this;
	}
	Application::~Application(){
		delete m_window;
	}
	void* Application::GetNativeWindow(){
		return m_window->GetWindow();
	}
	void Application::AddLayer(Layer l) {
		m_layerStack.emplace_back(l);
	}
	void Application::OnEvent(Event& ev){
		
		for (int i = 0; i < m_layerStack.size(); i++) {
			m_layerStack[i].OnEvent(ev);
		}
	}
	void Application::Run() {	
		while (m_running) {
			m_running = m_window->OnUpdate();
			++TickCount;
			evQueue::Handle ev = evQueue::GetNextEvents();
			for(int i = 0; i < ev.numOfEvents; i++){
				OnEvent(evQueue::queue[ev.head]);
				ev.head++;
			}
			if (IsKeyDown(KEY_CODE::A)) {
				IRD_CORE_INFO("A is down");
			}
		}
	}

}
 