#include "app.h"
#include "GLFW/glfw3.h"
#include "neko/imgui/imgui_layer.h"
#include "neko/renderer/Buffer.h"
#include "neko/renderer/VertexArray.h"
#include "neko/renderer/shader.h"
#include <cstdint>
#include <functional>
#include <memory>
#define GLFW_INCLUDE_NONE
#include "log.h"
#include "input.h"
#include <utility>
#include "neko/renderer/renderer.h"

namespace NEKO
{

    #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        if (!s_Instance) NEKO_CORE_WARN("App already exist");
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

        m_imgui_layer = new imgui_layer();
        PushOverlay(m_imgui_layer);

    }

    Application::~Application() {}

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if(e.m_Handled) break;
        }
    }

    void Application::run()
    {
        while(m_Running) {

            float time = static_cast<float>(glfwGetTime()); // Temporary::GetTime
            Timestep timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;

            for (Layer *layer : m_LayerStack) layer->OnUpdate(timestep);

            m_imgui_layer->Begin();
            for (Layer *layer : m_LayerStack) layer->OnImGuiRender();
            m_imgui_layer->End();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

}
