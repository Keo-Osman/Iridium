#pragma once
#include <iostream>
#include "Iridium/Core/Window.h"
namespace Ird {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		bool IsRunning();
		void Run();
	private:
		Window* m_window;
		bool m_running;
	};

	//Client defined
	Application* CreateApp();
}

