#include "irpch.h"
#include "Event.h"
#include "Iridium/Core/Log.h"
namespace Ird{
    u8 Queue::head = 0;
    u8 Queue::tail = 0;
    Event Queue::evQueue[255];
    void Queue::init(){
        Queue::emptyEvent = Event();
    }
    void Queue::AddKeyPressEvent(u16 keycode, bool repeat){
        //IRD_CORE_INFO("Tail was: {}", tail);
        evQueue[tail] = Event(_KeyPressed, (EVENT_CATEGORY)(_EventCategoryInput | _EventCategoryKeyboard), keycode, repeat);
        tail = (++tail) % SIZE;
        //IRD_CORE_INFO("Tail is now: {}", tail);
    }
    void Queue::AddKeyReleaseEvent(u16 keycode){
        //IRD_CORE_INFO("Tail was: {}", tail);
        Event(_KeyPressed, (EVENT_CATEGORY)(_EventCategoryInput | _EventCategoryKeyboard), keycode);
        tail = (++tail) % SIZE;
        //IRD_CORE_INFO("Tail is: {}", tail);
    }
    Event* Queue::GetNextEvent(){
        //IRD_CORE_INFO("Head was: {}", head);
        auto ret = &evQueue[head];
        if (ret->handled) {
            return &emptyEvent;
        }
        head = (++head) % SIZE;
        return ret;
    }
}