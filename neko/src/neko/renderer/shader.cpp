#include "shader.h"
#include "NPCH.h"
#include "neko/log.h"
#include "neko/platform/opengl/OpenGlShadder.h"
#include "neko/renderer/renderer.h"
#include "neko/platform/opengl/OpenGLVertexArray.h"

namespace NEKO
{
    Shadder* Shadder::Create(const std::string &filepath)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                NEKO_CORE_ERR("NOT SUpported");
                return nullptr;
            }

            case RendererAPI::API::OpenGL: return new OpenGLShadder(filepath);
        }

        NEKO_CORE_ERR("Unkown API");
        return nullptr;
    }

    Shadder* Shadder::Create(const std::string &vertex_src, const std::string &fragment_src)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                NEKO_CORE_ERR("NOT SUpported");
                return nullptr;
            }

            case RendererAPI::API::OpenGL: return new OpenGLShadder(vertex_src, fragment_src);
        }

        NEKO_CORE_ERR("Unkown API");
        return nullptr;
    }


}
