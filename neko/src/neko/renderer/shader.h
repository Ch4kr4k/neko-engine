#pragma once
#define GLFW_INCLUDE_NONE
#include "NPCH.h"
#include <cstddef>
#include <glm/glm.hpp>
#include <cstdint>

namespace NEKO
{
    class Shadder {
        public:
            virtual ~Shadder() = default;

            virtual void Bind() const = 0;
            virtual void UnBind() const = 0;

            static Shadder *Create(const std::string &vertex_src, const std::string &fragment_src);
        private:
            uint32_t m_RendererID;
    };
}
