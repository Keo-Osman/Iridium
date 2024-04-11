#pragma once
#include "irpch.h"
#include "Iridium/Core/Window.h"
#include "Iridium/Event/Event.h"
namespace Ird {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		bool IsRunning();
		void Run();
		void OnEvent(evQueue::Handle ev);
	private:
		Window* m_window;
		bool m_running;
	};

	//Client defined
	Application* CreateApp();
}

