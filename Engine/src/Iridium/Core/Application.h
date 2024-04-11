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
		//Return a pointer to m_window this will be of differnt type depending on platform /lib we use
		void* GetNativeWindow();
	private:
		Window* m_window;
		bool m_running;
	};

	//Client defined
	Application* CreateApp();
}

