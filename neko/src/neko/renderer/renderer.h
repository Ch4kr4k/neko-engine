#pragma once
#include "RenderCommand.h"
#include "neko/renderer/VertexArray.h"
#include <memory>
#include "OrthographicCamera.h"
#include "neko/renderer/shader.h"

namespace NEKO
{
    class Renderer{
        public:
            static void BeginScene(OrthographicCamera &camera);
            static void Init();
            static void EndScene();

            static void Submit(const Ref<Shadder> &shadder, const Ref<VertexArray>& vertexArray, const glm::mat4 &transform = glm::mat4(1.0f));
            inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

        private:

            struct SceneData {
                glm::mat4 ViewProjectionMatrix;
            };

            static SceneData *m_SceneData;

    };
}
