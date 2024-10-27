#pragma once

#include "neko/core.h"
#include "neko/layer.h"
#include "neko/Events/Event.h"
#include "neko/Events/appE.h"
#include "neko/Events/mouseE.h"
#include "neko/Events/keyE.h"

namespace NEKO
{
    class NekoApi imgui_layer : public Layer {
        public:
            imgui_layer();
            ~imgui_layer();

           virtual void OnAttach() override;
           virtual void OnDetach() override;
           virtual void OnImGuiRender() override;

           void Begin();
           void End();

        private:
            float m_Time = 0;
    };

    static void SetupImGuiKeyMapping();
}
