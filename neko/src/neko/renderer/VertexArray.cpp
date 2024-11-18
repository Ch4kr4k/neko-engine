#include "VertexArray.h"
#include "NPCH.h"
#include "neko/log.h"
#include "neko/renderer/renderer.h"
#include "neko/platform/opengl/OpenGLVertexArray.h"


namespace NEKO
{
    VertexArray *VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                NEKO_CORE_ERR("NOT SUpported");
                return nullptr;
            }

            case RendererAPI::API::OpenGL:
                return new OpenGLVertexArray();
        }

        NEKO_CORE_ERR("Unkown API");
        return nullptr;
    }
}
