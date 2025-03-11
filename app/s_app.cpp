#include "neko.h"
#include "neko/Events/Event.h"
#include "neko/Events/appE.h"
#include "neko/Events/keyE.h"
#include "neko/app.h"
#include "neko/input.h"
#include "neko/keycodes.h"
#include "neko/log.h"
#include "imgui.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include "neko/platform/opengl/OpenGlShadder.h"
#include "neko/renderer/Texture.h"
#include "neko/renderer/shader.h"
#include <glm/gtc/type_ptr.hpp>
#include <memory>

class ex_layer : public NEKO::Layer {
    public:
        ex_layer()
            : Layer("example"), m_CameraController(1280.0f / 720.0f, true),
              m_CameraPosition(0.0f),
              m_SquarePosition(0.0f)
        {
            m_VertexArray.reset(NEKO::VertexArray::Create());

            float vertices[3 * 7] = {
                -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f, // -x, -y , z 3rd quadrant
                0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,//  x, -y , z 4rd quadrant
                0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f //  x,  y,  z origin
            };

            NEKO::Ref<NEKO::VertexBuffer> vertexBuffer;
            vertexBuffer.reset(NEKO::VertexBuffer::Create(vertices, sizeof(vertices)));
            NEKO::BufferLayout layout = {
                { NEKO::ShaderDataType::Float3, "a_Position" },
                { NEKO::ShaderDataType::Float4, "a_Color" }
            };

            vertexBuffer->SetLayout(layout);
            m_VertexArray->AddVertexBuffer(vertexBuffer);

            uint32_t indices[3] = { 0, 1, 2};
            NEKO::Ref<NEKO::IndexBuffer> indexBuffer;
            indexBuffer.reset(NEKO::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
            m_VertexArray->SetIndexBuffer(indexBuffer);

            m_SquareVA.reset(NEKO::VertexArray::Create());

            float Squarevertices[5 * 4] = {
                -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
                0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
                0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
                -0.5f, 0.5f, 0.0f, 0.0f, 1.0f
            };

            NEKO::Ref<NEKO::VertexBuffer> SquareVB;
            SquareVB.reset(NEKO::VertexBuffer::Create(Squarevertices, sizeof(Squarevertices)));

            SquareVB->SetLayout({
                { NEKO::ShaderDataType::Float3, "a_Position" },
                { NEKO::ShaderDataType::Float2, "a_TexCoord" }
            });

            m_SquareVA->AddVertexBuffer(SquareVB);

            uint32_t Squareindices[6] = { 0, 1, 2, 2, 3, 0};
            NEKO::Ref<NEKO::IndexBuffer> squareIB;
            squareIB.reset(NEKO::IndexBuffer::Create(Squareindices, sizeof(Squareindices)/sizeof(uint32_t)));
            m_SquareVA->SetIndexBuffer(squareIB);

            std::string vertexSrc = R"(
                #version 430 core
                layout(location = 0) in vec3 a_Position;
                layout(location = 1) in vec4 a_Color;
                uniform mat4 u_ViewProjection;
                uniform mat4 u_Transform;
                out vec3 v_Position;
                out vec4 v_Color;
                void main()
                {
                    v_Position = a_Position;
                    v_Color = a_Color;
                    gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
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

            m_Shadder = (NEKO::Shadder::Create("VertexColourTriangle" , vertexSrc, fragmentSrc));

            std::string flatvertexSrc = R"(
                #version 430 core
                layout (location = 0) in vec3 a_Position;
                out vec3 v_Position;
                uniform mat4 u_ViewProjection;
                uniform mat4 u_Transform;
                void main()
                {
                    v_Position = a_Position;
                    gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
                }
            )";

            std::string flatfragmentSrc = R"(
                #version 430 core
                layout(location = 0) out vec4 color;

                in vec3 v_Position;
                uniform vec3 u_Color;
                void main()
                {
                    color = vec4(u_Color, 1.0);
                }
            )";

            m_BlueShadder = (NEKO::Shadder::Create("FlatColour", flatvertexSrc, flatfragmentSrc));

            // color = (v_TexCoord, 0.0, 1.0);
            m_TextureShadder = (NEKO::Shadder::Create("assets/shaders/Texture.glsl"));
            m_Texture = (NEKO::Texture2D::Create("assets/textures/Checkerboard.png"));
            m_Cherno_Logo = (NEKO::Texture2D::Create("assets/textures/ChernoLogo.png"));
            std::dynamic_pointer_cast<NEKO::OpenGLShadder>(m_TextureShadder)->Bind();
            int slot = 0;
            std::dynamic_pointer_cast<NEKO::OpenGLShadder>(m_TextureShadder)->UploadUniformInt("u_Texture", slot);
        }

        void OnUpdate(NEKO::Timestep ts) override
        {
            // Camera movement
            m_CameraController.OnUpdate(ts);

            // renderer
            NEKO::RenderCommand::SetClearColor({0.10588f, 0.10196f, 0.14902f, 1.0f});
            NEKO::RenderCommand::Clear();

            NEKO::Renderer::BeginScene(m_CameraController.GetCamera());

            glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

            std::dynamic_pointer_cast<NEKO::OpenGLShadder>(m_BlueShadder)->Bind();
            std::dynamic_pointer_cast<NEKO::OpenGLShadder>(m_BlueShadder)->UploadUniformFloat3("u_Color", m_SquareColor);

            for (int y=0; y < 20; ++y) {
                for (int x=0; x < 20 ; ++x) {
                    glm::vec3 pos(x * 0.11f, y* 0.11f, 0.0f);
                    glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                    NEKO::Renderer::Submit(m_BlueShadder, m_SquareVA, transform);
                }
            }

            m_Texture->Bind();
            NEKO::Renderer::Submit(m_TextureShadder, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
            m_Cherno_Logo->Bind();
            NEKO::Renderer::Submit(m_TextureShadder, m_SquareVA,
                glm::translate(glm::mat4(1.0f), glm::vec3(0.25f, -0.25f, 0.0f)) * glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
            // Triangle
            // NEKO::Renderer::Submit(m_Shadder, m_VertexArray);
            NEKO::Renderer::EndScene();
        }

        virtual void OnImGuiRender() override
        {
            ImGui::Begin("Settings");
            ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
            ImGui::End();
        }

        void OnEvent(NEKO::Event &e) override
        {
            m_CameraController.OnEvent(e);

            if (e.GetEventType() == NEKO::EventType::WindowResize) {
                auto &re = (NEKO::WindowResizeEvent&)e;
            }
        }

        //bool OnKeyPressedEvent(NEKO::KeyPressedEvent &event)
        //{

        //    //if(event.GetKeyCode() == NEKO_KEY_LEFT)
        //    //    m_CameraPosition.x -= m_CameraSpeed;

        //    //if(event.GetKeyCode() == NEKO_KEY_RIGHT)
        //    //    m_CameraPosition.x += m_CameraSpeed;

        //    //if(event.GetKeyCode() == NEKO_KEY_DOWN)
        //    //    m_CameraPosition.y -= m_CameraSpeed;

        //    //if(event.GetKeyCode() == NEKO_KEY_UP)
        //    //    m_CameraPosition.y += m_CameraSpeed;

        //    return false;
        //}

    private:
        NEKO::Ref<NEKO::Shadder> m_Shadder;
        NEKO::Ref<NEKO::Shadder> m_BlueShadder, m_TextureShadder;

        NEKO::Ref<NEKO::VertexArray> m_VertexArray;
        NEKO::Ref<NEKO::VertexArray> m_SquareVA;

        NEKO::Ref<NEKO::Texture2D> m_Texture, m_Cherno_Logo;

        NEKO::OrthographicCameraController m_CameraController;
        glm::vec3 m_CameraPosition;
        float m_CameraSpeed = 0.1f;
        float m_SquareMoveSpeed = 1.0f;
        glm::vec3 m_SquarePosition;

        glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f};
};

class SboxApp : public NEKO::Application{
    public:
        SboxApp()
        {
            PushLayer(new ex_layer());
            // PushOverlay(new NEKO::imgui_layer);
        }

        ~SboxApp()
        {

        }
};

NEKO::Application *NEKO::CreateApplication()
{
    return new SboxApp();
}
