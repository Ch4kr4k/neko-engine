#include "SandBox2D.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "neko/platform/opengl/OpenGlShadder.h"
#include "imgui.h"


Sandbox2D::Sandbox2D()
    : Layer("SandBox2D"), m_CameraController(1280.0f /720.0f)
{

}

void Sandbox2D::OnAttach()
{
    m_SquareVA = (NEKO::VertexArray::Create());

    float Squarevertices[5 * 4] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
    };

    NEKO::Ref<NEKO::VertexBuffer> SquareVB;
    SquareVB.reset(NEKO::VertexBuffer::Create(Squarevertices, sizeof(Squarevertices)));

    SquareVB->SetLayout({
        { NEKO::ShaderDataType::Float3, "a_Position" }
    });

    m_SquareVA->AddVertexBuffer(SquareVB);

    uint32_t Squareindices[6] = { 0, 1, 2, 2, 3, 0};
    NEKO::Ref<NEKO::IndexBuffer> squareIB;
    squareIB.reset(NEKO::IndexBuffer::Create(Squareindices, sizeof(Squareindices)/sizeof(uint32_t)));
    m_SquareVA->SetIndexBuffer(squareIB);

    m_FlatColorShader = NEKO::Shadder::Create("assets/shaders/FlatColor.glsl");


}

void Sandbox2D::OnDetach() {}

void Sandbox2D::OnUpdate(NEKO::Timestep ts)
{
    m_CameraController.OnUpdate(ts);

    // Render
    NEKO::RenderCommand::SetClearColor({0.10588f, 0.10196f, 0.14902f, 1.0f});
    NEKO::RenderCommand::Clear();

    NEKO::Renderer::BeginScene(m_CameraController.GetCamera());

    std::dynamic_pointer_cast<NEKO::OpenGLShadder>(m_FlatColorShader)->Bind();
    std::dynamic_pointer_cast<NEKO::OpenGLShadder>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

    NEKO::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
    NEKO::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(NEKO::Event &e)
{
    m_CameraController.OnEvent(e);
}
