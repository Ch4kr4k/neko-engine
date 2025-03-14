#include "NPCH.h"
#include "neko/platform/opengl/OpenGlShadder.h"
#include "neko/renderer/OrthographicCamera.h"
#include "neko/renderer/RenderCommand.h"
#include "neko/renderer/renderer2D.h"
#include <glm/fwd.hpp>
#include <memory>
#include "renderer.h"

namespace NEKO
{
    Renderer::SceneData *Renderer::m_SceneData = new Renderer::SceneData;
    void Renderer::BeginScene(OrthographicCamera &camera)
    {
        m_SceneData->ViewProjectionMatrix = camera.GetViewProjectMatrix();
    }

    void Renderer::OnWindowResize(uint32_t width, uint32_t height)
    {
        RenderCommand::SetViewport(0, 0, width, height);
    }

    void Renderer::Init()
    {
        RenderCommand::Init();
        Renderer2D::Init();
    }

    void Renderer::EndScene()
    {

    }

    void Renderer::Submit(const Ref<Shadder> &shadder, const Ref<VertexArray>& vertexArray, const glm::mat4 &transform)
    {
        shadder->Bind();
        std::dynamic_pointer_cast<OpenGLShadder>(shadder)->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
        std::dynamic_pointer_cast<OpenGLShadder>(shadder)->UploadUniformMat4("u_Transform", transform);

        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }

}
