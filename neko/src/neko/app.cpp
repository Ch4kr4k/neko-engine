#include "app.h"
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

        m_VertexArray.reset(VertexArray::Create());

        float vertices[3 * 7] = {
             -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f, // -x, -y , z 3rd quadrant
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,//  x, -y , z 4rd quadrant
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f //  x,  y,  z origin
        };

        std::shared_ptr<VertexBuffer> vertexBuffer;
        vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
        BufferLayout layout = {
            { ShaderDataType::Float3, "a_Position" },
            { ShaderDataType::Float4, "a_Color" }
        };

        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        uint32_t indices[3] = { 0, 1, 2};
        std::shared_ptr<IndexBuffer> indexBuffer;
        indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVA.reset(VertexArray::Create());

        float Squarevertices[3 * 4] = {
             -0.75f, -0.75f, 0.0f,
             0.75f, -0.75f, 0.0f,
             0.75f,  0.75f, 0.0f,
             -0.75f, 0.75f, 0.0f
        };

        std::shared_ptr<VertexBuffer> SquareVB;
        SquareVB.reset(VertexBuffer::Create(Squarevertices, sizeof(Squarevertices)));

        SquareVB->SetLayout({
            { ShaderDataType::Float3, "a_Position" }
        });

        m_SquareVA->AddVertexBuffer(SquareVB);

        uint32_t Squareindices[6] = { 0, 1, 2, 2, 3, 0};
        std::shared_ptr<IndexBuffer> squareIB;
        squareIB.reset(IndexBuffer::Create(Squareindices, sizeof(Squareindices)/sizeof(uint32_t)));
        m_SquareVA->SetIndexBuffer(squareIB);

        std::string vertexSrc = R"(
            #version 430 core
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            out vec3 v_Position;
            out vec4 v_Color;
            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSrc = R"(
            #version 430 core
            out vec4 color;
            in vec3 v_Position;
            in vec4 v_Color;
            void main()
            {
                // color = vec4(v_Position + 0.5 * 0.5, 1.0);
                color = v_Color;
            }
        )";

        m_Shadder.reset(new Shadder(vertexSrc, fragmentSrc));

        std::string BluevertexSrc = R"(
            #version 430 core
            layout (location = 0) in vec3 a_Position;
            out vec3 v_Position;

            void main()
            {
                v_Position = a_Position;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string BluefragmentSrc = R"(
            #version 430 core
            layout(location = 0) out vec4 color;

            in vec3 v_Position;
            void main()
            {
                color = vec4(0.2, 0.3, 0.8, 1.0);
            }
        )";

        m_BlueShadder.reset(new Shadder(BluevertexSrc, BluefragmentSrc));
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

            RenderCommand::SetClearColor({0.10588f, 0.10196f, 0.14902f, 1.0f});
            RenderCommand::Clear();

            Renderer::BeginScene();

            m_BlueShadder->Bind();
            Renderer::Submit(m_SquareVA);

            m_Shadder->Bind();
            Renderer::Submit(m_VertexArray);

            Renderer::EndScene();

            for (Layer *layer : m_LayerStack) layer->OnUpdate();

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
