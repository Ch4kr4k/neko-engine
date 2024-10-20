#include "NPCH.h"
#include "neko/Events/appE.h"
#include "neko/Events/keyE.h"
#include "neko/Events/mouseE.h"
#include "neko/core.h"
//#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "neko/layer.h"
#include "imgui_layer.h"
#include "neko/platform/opengl/imgui_impl_opengl3.h"
#include "neko/app.h"
#include <X11/X.h>

namespace NEKO
{
    imgui_layer::imgui_layer()
        : Layer("imgui") {}

    imgui_layer::~imgui_layer(){}

    void imgui_layer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO &io =  ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        SetupImGuiKeyMapping();

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void imgui_layer::OnDetach()
    {

    }

    void imgui_layer::OnUpdate()
    {

        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::Get();
        io.DisplaySize = { (float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight() };

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    }

    void imgui_layer::OnEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<MouseButtonPressed>(NEKO_BIND_EVENT_FN(imgui_layer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleased>(NEKO_BIND_EVENT_FN(imgui_layer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(NEKO_BIND_EVENT_FN(imgui_layer::OnMouseMoveEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(NEKO_BIND_EVENT_FN(imgui_layer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(NEKO_BIND_EVENT_FN(imgui_layer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleased>(NEKO_BIND_EVENT_FN(imgui_layer::OnKeyReleasedEvent));
        dispatcher.Dispatch<KeyTyped>(NEKO_BIND_EVENT_FN(imgui_layer::OnTypedEvent));
        dispatcher.Dispatch<WindowResizeEvent>(NEKO_BIND_EVENT_FN(imgui_layer::OnWindowResizedEvent));
    }

    bool imgui_layer::OnMouseButtonPressedEvent(MouseButtonPressed &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;
        return false;
    }

    bool imgui_layer::OnMouseButtonReleasedEvent(MouseButtonReleased &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;
        return false;
    }

    bool imgui_layer::OnMouseMoveEvent(MouseMovedEvent &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MousePos = { e.GetX(), e.GetY() };

        return false;
    }

    bool imgui_layer::OnMouseScrolledEvent(MouseScrolledEvent &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseWheel += e.GetXOffset();
        io.MouseWheelH += e.GetYOffset();

        return false;
    }

    bool imgui_layer::OnKeyPressedEvent(KeyPressedEvent &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = true;
        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
        return false;
    }

    bool imgui_layer::OnKeyReleasedEvent(KeyReleased &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = false;
        return false;
    }

    bool imgui_layer::OnTypedEvent(KeyTyped &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        int keycode = e.GetKeyCode();
        if (keycode > 0 && keycode < 0x10000) {
            io.AddInputCharacter((unsigned short)keycode);
        }

        return false;
    }

    bool imgui_layer::OnWindowResizedEvent(WindowResizeEvent &e)
    {
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = { (float)e.GetWidth(), (float)e.GetHeight() };
        io.DisplayFramebufferScale = {1.0f, 1.0f};
        glViewport(0, 0, e.GetWidth(), e.GetHeight());
        return false;
    }

    static void SetupImGuiKeyMapping() {
        ImGuiIO& io = ImGui::GetIO();

        // Map GLFW key codes to ImGui key indices
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        // Function keys
        for (int i = 0; i < 12; i++) {
            io.KeyMap[ImGuiKey_F1 + i] = GLFW_KEY_F1 + i;
        }

        // Numeric keys
        io.KeyMap[ImGuiKey_0] = GLFW_KEY_0;
        io.KeyMap[ImGuiKey_1] = GLFW_KEY_1;
        io.KeyMap[ImGuiKey_2] = GLFW_KEY_2;
        io.KeyMap[ImGuiKey_3] = GLFW_KEY_3;
        io.KeyMap[ImGuiKey_4] = GLFW_KEY_4;
        io.KeyMap[ImGuiKey_5] = GLFW_KEY_5;
        io.KeyMap[ImGuiKey_6] = GLFW_KEY_6;
        io.KeyMap[ImGuiKey_7] = GLFW_KEY_7;
        io.KeyMap[ImGuiKey_8] = GLFW_KEY_8;
        io.KeyMap[ImGuiKey_9] = GLFW_KEY_9;

        // Special keys
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Comma] = GLFW_KEY_COMMA;
        io.KeyMap[ImGuiKey_Minus] = GLFW_KEY_MINUS;
        io.KeyMap[ImGuiKey_Period] = GLFW_KEY_PERIOD;
        io.KeyMap[ImGuiKey_Slash] = GLFW_KEY_SLASH;

        io.KeyMap[ImGuiKey_CapsLock] = GLFW_KEY_CAPS_LOCK;
        io.KeyMap[ImGuiKey_ScrollLock] = GLFW_KEY_SCROLL_LOCK;
        io.KeyMap[ImGuiKey_NumLock] = GLFW_KEY_NUM_LOCK;

        // Arrow keys
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
    }
}
