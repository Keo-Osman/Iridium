#pragma once
#include <stdint.h>
namespace Ird{
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

    class Event{
    public:
        const EVENT_TYPE type;
        const uint32_t tickHappened;
    };
}