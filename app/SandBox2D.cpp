#include "SandBox2D.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "neko/platform/opengl/OpenGlShadder.h"
#include "imgui.h"
#include "neko/renderer/renderer2D.h"


Sandbox2D::Sandbox2D()
    : Layer("SandBox2D"), m_CameraController(1280.0f /720.0f)
{

}

void Sandbox2D::OnAttach()
{

}

void Sandbox2D::OnDetach() {}

void Sandbox2D::OnUpdate(NEKO::Timestep ts)
{
    m_CameraController.OnUpdate(ts);

    // Render
    NEKO::RenderCommand::SetClearColor({0.10588f, 0.10196f, 0.14902f, 1.0f});
    NEKO::RenderCommand::Clear();

    NEKO::Renderer2D::BeginScene(m_CameraController.GetCamera());
    NEKO::Renderer2D::DrawQuad({0.0f, 0.0f}, {1.0f, 1.0f}, {0.8f, 0.2f, 0.3f, 1.0f});
    NEKO::Renderer2D::EndScene();

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
