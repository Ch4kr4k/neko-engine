#pragma once

#include "core.h"
#include "Events/Event.h"
#include "neko/core/Timestep.h"

namespace NEKO
{
    class NekoApi Layer{
        public:
            Layer(const std::string &name = "Layer");
            virtual ~Layer();

            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnUpdate(Timestep ts) {}
            virtual void OnEvent(Event &event) {}
            virtual void OnImGuiRender() {}

            inline const std::string &GetName() const { return m_DebugName; }
        private:
            std::string m_DebugName;
    };
}
