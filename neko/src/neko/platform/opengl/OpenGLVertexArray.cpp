#include "NPCH.h"
#include "OpenGLVertexArray.h"
#include "glad/glad.h"
#include "neko/renderer/Buffer.h"
#include <memory>

namespace NEKO
{
    static GLenum ShaderDataTypeToOpengGLBaseType(ShaderDataType type)
    {
        switch (type) {
            case ShaderDataType::Float:    return GL_FLOAT;
            case ShaderDataType::Float2:   return GL_FLOAT;
            case ShaderDataType::Float3:   return GL_FLOAT;
            case ShaderDataType::Float4:   return GL_FLOAT;
            case ShaderDataType::Mat3:     return GL_FLOAT;
            case ShaderDataType::Mat4:     return GL_FLOAT;
            case ShaderDataType::Int:      return GL_INT;
            case ShaderDataType::Int2:     return GL_INT;
            case ShaderDataType::Int3:     return GL_INT;
            case ShaderDataType::Int4:     return GL_INT;
            case ShaderDataType::Bool:     return GL_BOOL;
            case ShaderDataType::None: {
                NEKO_CORE_ERR("Unkown Shadder Data Type");
                return 0;
            }
        }
        return 0;
    }

    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &m_RendererId);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererId);
    }
    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererId);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>&vertexBuffer)
    {
        glBindVertexArray(m_RendererId);
        vertexBuffer->Bind();

        if(!vertexBuffer->GetLayout().GetElements().size())
            NEKO_CORE_ERR("Vertex Buffer has no layout");

        uint32_t index = 0;
        const auto &layout = vertexBuffer->GetLayout();
        for (const auto& element : layout) {
            glEnableVertexAttribArray(index);

            glVertexAttribPointer(
                index,
                element.GetComponentCount(),
                ShaderDataTypeToOpengGLBaseType(element.Type),
                element.Normalized ? GL_TRUE : GL_FALSE,
                layout.GetStride(),
                (const void*)element.Offset
            );
            index++;
        }

        m_VertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
    {
        glBindVertexArray(m_RendererId);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }


}
