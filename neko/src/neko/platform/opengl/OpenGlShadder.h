#pragma once
#include "neko/renderer/shader.h"
#define GLFW_INCLUDE_NONE
#include "NPCH.h"
#include <cstddef>
#include <glm/glm.hpp>
#include <cstdint>

namespace NEKO
{
    class OpenGLShadder : public Shadder {
        public:
            OpenGLShadder(const std::string &vertex_src, const std::string& fragment_src);
            virtual ~OpenGLShadder();

            void Bind() const override;
            void UnBind() const override;

            void UploadUniformInt(const std::string &name ,int &values);

            void UploadUniformFloat(const std::string &name ,float &values);
            void UploadUniformFloat2(const std::string &name ,const glm::vec2 &values);
            void UploadUniformFloat3(const std::string &name ,const glm::vec3 &values);
            void UploadUniformFloat4(const std::string &name ,const glm::vec4 &values);

            void UploadUniformMat3(const std::string &name ,const glm::mat3 &matrix);
            void UploadUniformMat4(const std::string &name ,const glm::mat4 &matrix);

        private:
            uint32_t m_RendererID;
    };
}
