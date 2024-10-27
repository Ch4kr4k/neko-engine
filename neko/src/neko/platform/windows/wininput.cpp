#include "wininput.h"
#include "NPCH.h"
#include "neko/app.h"
#include <GLFW/glfw3.h>

namespace NEKO
{
    Input* Input::s_Instances = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int KeyCode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, KeyCode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;

    }

    std::pair<float, float> WindowsInput::GetMousePosImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {float(xpos), float(ypos)};
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto [x, _] = GetMousePosImpl(); // v = std::get<pos>(var);
        return x;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto [_, y] = GetMousePosImpl();
        return y;
    }


}
