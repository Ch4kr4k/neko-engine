#pragma once
#define GLFW_INCLUDE_NONE
#include "NPCH.h"
#include <cstddef>
#include <cstdint>

namespace NEKO
{
    class Shadder {
        public:
            Shadder(const std::string &vertex_src, const std::string& fragment_src);
            ~Shadder();

            void Bind() const;
            void UnBind() const;

        private:
            uint32_t m_RendererID;
    };
}
