#pragma once
#include "Iridium/Event/Event.h"
namespace Ird {
	class Layer {
	public:
		virtual void OnEvent(Event& e) {};
		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnImGuiRender() {};
	};
}