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
        //Which event the window originated from
        const uint8_t windowID;
        //Debug Event records exact tick it happened
        #ifdef IRD_DEBUG
        const uint32_t tickHappened;
        #endif
    };
}