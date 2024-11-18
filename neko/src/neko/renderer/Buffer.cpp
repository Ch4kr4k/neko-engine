#include "Buffer.h"
#include "neko/log.h"
#include "neko/platform/opengl/OpenGlBuffer.h"
#include "renderer.h"

namespace NEKO
{
    // ############## Vertex ##############
    //
    VertexBuffer* VertexBuffer::Create(float *vertices, uint32_t size)
    {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None: return  nullptr;
            case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
        }

        NEKO_CORE_ERR("API Not Supported");
        return nullptr;
    }

    VertexBuffer::~VertexBuffer() {}


    // ########## INDEX BUFFER ##########

    IndexBuffer* IndexBuffer::Create(uint32_t *indices, uint32_t size)
    {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None: return  nullptr;
            case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);
        }

        NEKO_CORE_ERR("API Not Supported");
        return nullptr;
    }

    IndexBuffer::~IndexBuffer() {}
}
