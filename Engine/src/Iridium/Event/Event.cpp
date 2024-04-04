#include "Event.h"
namespace Ird{
    namespace EvQueue{
        std::deque<Event*> m_eventQueue;
    }
    void EvQueue::AddEvent(Event* e){m_eventQueue.push_back(e);}
    Event* EvQueue::GetEvent() {return m_eventQueue.front();}
}