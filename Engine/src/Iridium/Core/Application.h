#pragma once
#include "irpch.h"
#include "Iridium/Core/Window.h"
#include "Iridium/Event/Event.h"
#include "Iridium/Core/Layer.h"
namespace Ird {
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& ev);
		//Return a pointer to m_window this will be of differnt type depending on platform / window library we use
		void* getNativeWindow();
		void AddLayer(Layer l);

		static Application* get() { return s_instance; }
	private:
		Window* m_window;
		bool m_running;
		static Application* s_instance;
		std::vector<Layer> m_layerStack;
	};

	//Client defined
	Application* CreateApp();
}

