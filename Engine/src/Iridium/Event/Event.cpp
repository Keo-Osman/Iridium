#include "irpch.h"
#include "Iridium/Event/Event.h"
#include "Iridium/Core/Log.h"
namespace Ird{
    u8 evQueue::head = 0;
    u8 evQueue::tail = 0;
    Event evQueue::queue[255];

    //Calling constuctor is actually faster than modifying data in these add functions **WITH OPTIMISATIONS** as the evnt constuctor is trivial and can be optimised out 
    //Se evConstructor in Optimisation explain
    void evQueue::AddKeyPressEvent(u16 keycode, bool repeat){
        queue[tail] = Event(EVENT_TYPE::KeyPressed, (EVENT_CATEGORY::Input | EVENT_CATEGORY::Keyboard), keycode, repeat);
        tail = (tail +1 ) % SIZE;
    }
    void evQueue::AddKeyReleaseEvent(u16 keycode){
        queue[tail] = Event(EVENT_TYPE::KeyReleased, (EVENT_CATEGORY::Input | EVENT_CATEGORY::Keyboard), keycode);
        tail = (tail + 1) % SIZE;
    }

    void evQueue::AddMousePressEvent(u16 mousecode){
        queue[tail] = Event(EVENT_TYPE::MouseButtonPressed, (EVENT_CATEGORY::Input | EVENT_CATEGORY::MouseButton), mousecode);
        tail = (tail + 1) % SIZE;
    }
    void evQueue::AddMouseReleaseEvent(u16 mousecode){
        queue[tail] = Event(EVENT_TYPE::MouseButtonReleased, (EVENT_CATEGORY::Input | EVENT_CATEGORY::MouseButton), mousecode);
        tail = (tail + 1) % SIZE;
    }
    void evQueue::AddMouseMoveEvent(f32 x, f32 y){
        queue[tail] = Event(EVENT_TYPE::MouseMoved, (EVENT_CATEGORY::Input | EVENT_CATEGORY::Mouse), x, y);
        tail = (tail + 1) % SIZE;
    }
    void evQueue::AddMouseScrollEvent(f32 x, f32 y){
        queue[tail] = Event(EVENT_TYPE::MouseScrolled, (EVENT_CATEGORY::Input | EVENT_CATEGORY::Mouse), x, y);
        tail = (tail + 1) % SIZE;
    }

    void evQueue::AddWindowCloseEvent(){
        queue[tail] = Event(EVENT_TYPE::WindowClosed, EVENT_CATEGORY::Application);
        tail = (tail + 1) % SIZE;
    }
    void evQueue::AddWindowResizeEvent(u16 width, u16 height){
        queue[tail] = Event(EVENT_TYPE::WindowResized, EVENT_CATEGORY::Application, width, height);
        tail = (tail + 1) % SIZE;
    }

    evQueue::Handle evQueue::GetNextEvents() {
        u8 retHead = head;
        u8 numOfEvents= 0;
        while(head != tail){
            head = (head + 1) % SIZE;
            numOfEvents++;
        }
        return {numOfEvents, retHead};
    }
}