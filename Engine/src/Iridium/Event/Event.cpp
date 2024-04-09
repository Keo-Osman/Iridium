#include "irpch.h"
#include "Iridium/Event/Event.h"
#include "Iridium/Core/Log.h"
namespace Ird{
    u8 Queue::head = 0;
    u8 Queue::tail = 0;
    Event Queue::evQueue[255];
    Event Queue::emptyEvent;

    void Queue::AddKeyPressEvent(u16 keycode, bool repeat){
        //IRD_CORE_INFO("Tail was: {}", tail);
        evQueue[tail] = Event(_KeyPressed, (EVENT_CATEGORY)(_EventCategoryInput | _EventCategoryKeyboard), keycode, repeat);
        tail = (tail +1 ) % SIZE;
        //IRD_CORE_INFO("Tail is now: {}", tail);
    }
    void Queue::AddKeyReleaseEvent(u16 keycode){
        //IRD_CORE_INFO("Tail was: {}", tail);
        evQueue[tail] = Event(_KeyReleased, (EVENT_CATEGORY)(_EventCategoryInput | _EventCategoryKeyboard), keycode);
        tail = (tail + 1) % SIZE;
        //IRD_CORE_INFO("Tail is: {}", tail);
    }
    Event* Queue::GetNextEvent() {
        Event* ret = &evQueue[head];
        if (ret->type == EVENT_TYPE::_None) {
            while (evQueue[(head + 1) % SIZE].handled == false && evQueue[(head + 1) % SIZE].type != EVENT_TYPE::_None) {
                head = (head + 1) % SIZE;
            }
            return &emptyEvent; // If all events are handled, return emptyEvent
        }
        else {
            while (evQueue[(head + 1) % SIZE].handled == false && evQueue[(head + 1) % SIZE].type != EVENT_TYPE::_None) {
                head = (head + 1) % SIZE;
            }
            return ret;
        }
    }


    void Queue::ResetEvent(Event* e){
        e->category = EVENT_CATEGORY::_EventCategoryNone;
        e->type = EVENT_TYPE::_None;
        head = (head + 1) % SIZE;
    }
}