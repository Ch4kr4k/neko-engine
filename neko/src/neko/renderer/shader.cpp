#include "shader.h"
#include "NPCH.h"
#include "neko/log.h"
#include "neko/platform/opengl/OpenGlShadder.h"
#include "neko/renderer/renderer.h"
#include "neko/platform/opengl/OpenGLVertexArray.h"
#include <memory>

namespace NEKO
{
    Ref<Shadder> Shadder::Create(const std::string &filepath)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                NEKO_CORE_ERR("NOT SUpported");
                return nullptr;
            }

            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShadder>(filepath);
        }

        NEKO_CORE_ERR("Unkown API");
        return nullptr;
    }

    Ref<Shadder> Shadder::Create(const std::string &name , const std::string &vertex_src, const std::string &fragment_src)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                NEKO_CORE_ERR("NOT SUpported");
                return nullptr;
            }

            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShadder>(name, vertex_src, fragment_src);
        }

        NEKO_CORE_ERR("Unkown API");
        return nullptr;
    }
// --------------------- Shadder Library ---------------------------
    void ShaderLibrary::Add(const std::string &name, const Ref<Shadder> &shader)
    {
        if (!(Exists(name))) NEKO_CORE_WARN("Shadder Already Exist");
        m_Shaders[name] = shader;
    }

    void ShaderLibrary::Add(const Ref<Shadder> &shader)
    {
        auto &name = shader->GetName();
        Add(name, shader);
    }

    Ref<Shadder> ShaderLibrary::Load(const std::string &filepath)
    {
        auto shader = Shadder::Create(filepath);
        Add(shader);
        return shader;
    }

    Ref<Shadder> ShaderLibrary::Load(const std::string &name, const std::string &filepath)
    {
        auto shader = Shadder::Create(filepath);
        Add(shader);
        return shader;
    }

    Ref<Shadder> ShaderLibrary::Get(const std::string &name)
    {
        if (Exists(name)) NEKO_CORE_ERR("Shadder Not Found");
        return m_Shaders[name];
    }

    bool ShaderLibrary::Exists(const std::string &name) const
    {
        return m_Shaders.find(name) != m_Shaders.end();
    }
}
