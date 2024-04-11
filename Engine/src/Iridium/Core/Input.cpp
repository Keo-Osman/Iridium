#include "irpch.h"
#include "Input.h"
namespace Ird {
    bool IsKeyDown(Application* app, u16 keycode){
        return glfwGetKey((GLFWwindow*)app->GetNativeWindow(), keycode);
    }
}