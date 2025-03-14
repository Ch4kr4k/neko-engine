#include "renderer2D.h"
#include "NPCH.h"
#include "neko/renderer/RenderCommand.h"
#include "neko/renderer/VertexArray.h"
#include "neko/renderer/shader.h"
#include "neko/platform/opengl/OpenGlShadder.h"
#include <glm/fwd.hpp>

namespace NEKO
{
    struct Renderer2DStorage
    {
        Ref<VertexArray> VertexArr;
        Ref<Shadder> FlatColorShader;
    };

    static Renderer2DStorage* s_Data;

    void Renderer2D::Init()
    {
        s_Data = new Renderer2DStorage();
        s_Data->VertexArr = (VertexArray::Create());

        float Squarevertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.5f,  0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f,
        };

        Ref<VertexBuffer> SquareVB;
        SquareVB.reset(VertexBuffer::Create(Squarevertices, sizeof(Squarevertices)));

        SquareVB->SetLayout({
            { ShaderDataType::Float3, "a_Position" }
        });

        s_Data->VertexArr->AddVertexBuffer(SquareVB);

        uint32_t Squareindices[6] = { 0, 1, 2, 2, 3, 0};
        Ref<IndexBuffer> squareIB;
        squareIB.reset(IndexBuffer::Create(Squareindices, sizeof(Squareindices)/sizeof(uint32_t)));
        s_Data->VertexArr->SetIndexBuffer(squareIB);

        s_Data->FlatColorShader = Shadder::Create("assets/shaders/FlatColor.glsl");
    }

    void Renderer2D::Shutdown()
    {
        delete s_Data;
    }

    void Renderer2D::BeginScene(const OrthographicCamera &camera)
    {
        std::dynamic_pointer_cast<OpenGLShadder>(s_Data->FlatColorShader)->Bind();
        std::dynamic_pointer_cast<OpenGLShadder>(s_Data->FlatColorShader)->UploadUniformMat4("u_ViewProjection", camera.GetProjectionMatrix());
        std::dynamic_pointer_cast<OpenGLShadder>(s_Data->FlatColorShader)->UploadUniformMat4("u_Transform", glm::mat4(1.0f));
    }

    void Renderer2D::EndScene()
    {

    }

    void Renderer2D::DrawQuad(const glm::vec2 &position, const glm::vec2 &size, const glm::vec4 &color)
    {
        DrawQuad({position.x, position.y, 0.0f}, size, color);
    }

    void Renderer2D::DrawQuad(const glm::vec3 &position, const glm::vec2 &size, const glm::vec4 &color)
    {
        std::dynamic_pointer_cast<OpenGLShadder>(s_Data->FlatColorShader)->Bind();
        std::dynamic_pointer_cast<OpenGLShadder>(s_Data->FlatColorShader)->UploadUniformFloat4("u_Color", color);
        s_Data->VertexArr->Bind();
        RenderCommand::DrawIndexed(s_Data->VertexArr);
    }
}
