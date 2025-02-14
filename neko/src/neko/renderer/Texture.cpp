#include "Texture.h"
#include "neko/log.h"
#include "renderer.h"
#include "neko/platform/opengl/OpenGLTexture.h"
#include <memory>

namespace NEKO
{
    Ref<Texture2D> Texture2D::Create(const std::string &path)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                NEKO_CORE_ERR("NOT SUpported");
                return nullptr;
            }

            case RendererAPI::API::OpenGL:
                return std::make_shared<OpenGLTexture2D>(path);
        }

        NEKO_CORE_ERR("Unkown API");
        return nullptr;
    }

}
