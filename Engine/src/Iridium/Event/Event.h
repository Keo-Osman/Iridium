#pragma once
#include "EventDefines.h"
#include "irpch.h"
namespace Ird{
    namespace Event{
        struct KeyPressedEvent{
            _EVENT_CLASS_TYPE(EVENT_TYPE::KeyPressed)
            _EVENT_CLASS_CATEGORY(EVENT_CATEGORY::EventCategoryInput | EVENT_CATEGORY::EventCategoryKeyboard);
            u16 m_keyCode = -1;
            bool m_isRepeat = false;
        };
        struct KeyReleasedEvent{
            _EVENT_CLASS_TYPE(EVENT_TYPE::KeyReleased)
            _EVENT_CLASS_CATEGORY(EVENT_CATEGORY::EventCategoryInput | EVENT_CATEGORY::EventCategoryKeyboard);
            u16 m_keyCode = -1;
        };
        union Event_Context{
            Event_Context() : Empty(nullptr){}
            void* Empty;
            KeyPressedEvent m_keyPress;
            KeyReleasedEvent m_keyRelease;
        };
        class Event{
        public:
            Event_Context data;

        };


        namespace Queue{
            //Events will be inserted at the tail and handled at the head
            constexpr u8 SIZE = 255;
            extern Event evQueue[SIZE];
            extern u8 head;
            extern u8 tail;
            Event& GetNextEvent();
            void init();
            //Add Events
            void AddKeyPressEvent(u16 keycode, bool repeat);
            void AddKeyReleaseEvent(u16 keycode);

            //Debug function
            void Flush();
        }

    }
}
