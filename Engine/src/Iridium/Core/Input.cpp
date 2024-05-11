#include "irpch.h"
#include "Input.h"
namespace Ird {
    bool IsKeyDown(u16 keycode){
        return glfwGetKey((GLFWwindow*)Application::Get()->GetNativeWindow(), keycode);
    }
}