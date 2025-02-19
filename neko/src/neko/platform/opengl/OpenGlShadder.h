#pragma once
#include "neko/renderer/shader.h"
#include <unordered_map>
#define GLFW_INCLUDE_NONE
#include "NPCH.h"
#include <cstddef>
#include <glm/glm.hpp>
#include <cstdint>

typedef unsigned int GLenum;
namespace NEKO
{
    class OpenGLShadder : public Shadder {
        public:
            OpenGLShadder(const std::string &filepath);
            OpenGLShadder(const std::string &name, const std::string &vertex_src, const std::string& fragment_src);
            virtual ~OpenGLShadder();

            virtual void Bind() const override;
            virtual void UnBind() const override;
            virtual const std::string &GetName() override {return m_Name;};

            void UploadUniformInt(const std::string &name ,int &values);

            void UploadUniformFloat(const std::string &name ,float &values);
            void UploadUniformFloat2(const std::string &name ,const glm::vec2 &values);
            void UploadUniformFloat3(const std::string &name ,const glm::vec3 &values);
            void UploadUniformFloat4(const std::string &name ,const glm::vec4 &values);

            void UploadUniformMat3(const std::string &name ,const glm::mat3 &matrix);
            void UploadUniformMat4(const std::string &name ,const glm::mat4 &matrix);

        private:
            std::string ReadFile(const std::string &filepath);
            std::unordered_map<GLenum, std::string>PreProcess(const std::string &source);
            void Compile(const std::unordered_map<GLenum, std::string> &shadderSources);
        private:
            uint32_t m_RendererID;
            std::string m_Name;
    };
}
