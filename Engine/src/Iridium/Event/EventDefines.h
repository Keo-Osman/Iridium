#pragma once
#define _EVENT_CLASS_TYPE(type) static EVENT_TYPE GetStaticType() { return type; }\
								virtual EVENT_TYPE GetEventType() const override { return GetStaticType(); }\


#define _EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; };
#define _BIT_IN_PLACE(x) (1 << x)
namespace Ird {
    enum class EVENT_TYPE //: uint_fast16_t
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

    enum EVENT_CATEGORY //: uint_fast16_t
    {
        None = 0,
        EventCategoryApplication = _BIT_IN_PLACE(0),
        EventCategoryInput = _BIT_IN_PLACE(1),
        EventCategoryKeyboard = _BIT_IN_PLACE(2),
        EventCategoryMouse = _BIT_IN_PLACE(3),
        EventCategoryMouseButton = _BIT_IN_PLACE(4)
    };
}
