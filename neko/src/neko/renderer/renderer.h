#pragma once
#include "RenderCommand.h"
#include "neko/renderer/VertexArray.h"
#include <memory>
namespace NEKO
{
    class Renderer{
        public:
            static void BeginScene();
            static void EndScene();

            static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

            inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
    };
}
