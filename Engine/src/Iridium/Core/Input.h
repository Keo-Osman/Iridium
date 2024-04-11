#pragma once
#include "irpch.h"
#include "Defines.h"
#include "Iridium/Event/EventDefines.h"
#include "Iridium/Core/Application.h"
#ifdef IRD_WINDOW_GLFW
#include <GLFW/glfw3.h>
#endif // IRD_WINDOW_GLFW

namespace Ird {
    bool IsKeyDown(Application* app, u16 keycode);
}