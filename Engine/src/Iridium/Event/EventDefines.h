#pragma once
#include "Defines.h"
#define _EVENT_CLASS_TYPE(type) static EVENT_TYPE GetStaticType() { return type; }\
								virtual EVENT_TYPE GetEventType() const override { return GetStaticType(); }\


#define _EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; };
namespace Ird {
    enum EVENT_TYPE 
    {
        // Input Events
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseMoved,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseScrolled,

        // Window Events
        WindowResized,
        WindowClosed,
        WindowFocused,
        WindowLostFocus
    };

    enum EVENT_CATEGORY 
    {
        None = 0,
        EventCategoryApplication = _BIT_IN_PLACE(0),
        EventCategoryInput = _BIT_IN_PLACE(1),
        EventCategoryKeyboard = _BIT_IN_PLACE(2),
        EventCategoryMouse = _BIT_IN_PLACE(3),
        EventCategoryMouseButton = _BIT_IN_PLACE(4)
    };
}
