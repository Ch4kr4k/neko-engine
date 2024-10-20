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

            void OnAttach();
            void OnDetach();
            void OnUpdate();
            void OnEvent(Event &event);

        private:
            bool OnMouseButtonPressedEvent(MouseButtonPressed &e);
            bool OnMouseButtonReleasedEvent(MouseButtonReleased &e);
            bool OnMouseMoveEvent(MouseMovedEvent &e);
            bool OnMouseScrolledEvent(MouseScrolledEvent &e);
            bool OnKeyPressedEvent(KeyPressedEvent &e);
            bool OnKeyReleasedEvent(KeyReleased &e);
            bool OnTypedEvent(KeyTyped &e);
            bool OnWindowResizedEvent(WindowResizeEvent &e);

        private:
            float m_Time = 0;

        
    };

    static void SetupImGuiKeyMapping();
}
