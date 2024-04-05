#pragma once
#include "EventDefines.h"
#include "irpch.h"
namespace Ird{

    class Event{
    public:
        virtual ~Event() = default;

		bool Handled = false;

		virtual EVENT_TYPE GetEventType() const = 0;
        virtual int GetCategoryFlags() const = 0;
        bool IsInCategory(EVENT_CATEGORY category)
		{
			return GetCategoryFlags() & category;
		}
    };

    namespace EvQueue{
        void AddEvent(Event* e);
        Event* GetEvent();
        extern std::deque<Event*> m_eventQueue;
    }
}
