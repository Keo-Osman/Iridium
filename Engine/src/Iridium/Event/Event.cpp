#include "Event.h"
namespace Ird{
    namespace Event{
            u8 Queue::head = 0;
            u8 Queue::tail = 0;
            Event Queue::evQueue[255];
            void Queue::AddKeyPressEvent(u16 keycode, bool repeat){
                evQueue[tail].data.m_keyPress.m_keyCode = keycode;
                evQueue[tail].data.m_keyPress.m_isRepeat = repeat;
                tail = (++tail) % SIZE;
            }
            void Queue::AddKeyReleaseEvent(u16 keycode){
                evQueue[tail].data.m_keyRelease.m_keyCode = keycode;
                tail = (++tail) % SIZE;
            }
            Event& Queue::GetNextEvent(){
                return evQueue[head];
                head = (++head) % SIZE;
            }
    }
}