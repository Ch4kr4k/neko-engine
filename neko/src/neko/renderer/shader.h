#pragma once
#include "neko/core.h"
#include <string>
#include <unordered_map>
#define GLFW_INCLUDE_NONE
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
            virtual const std::string &GetName() = 0;

            static Ref<Shadder> Create(const std::string &filepath);
            static Ref<Shadder> Create(const std::string &name , const std::string &vertex_src, const std::string &fragment_src);
        private:
            uint32_t m_RendererID;
    };

    class ShaderLibrary {
        public:
            void Add(const Ref<Shadder> &shader);
            void Add(const std::string &name, const Ref<Shadder> &shader);
            Ref<Shadder> Load(const std::string &filepath);
            Ref<Shadder> Load(const std::string &name, const std::string &filepath);

            Ref<Shadder> Get(const std::string &name);

            bool Exists(const std::string &name) const;
        private:
            std::unordered_map<std::string, Ref<Shadder>> m_Shaders;
    };
}
