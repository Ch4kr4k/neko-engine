#pragma once

#include "core.h"
#include "Events/Event.h"
#include "neko/renderer/Buffer.h"
#include "neko/renderer/OrthographicCamera.h"
#include "neko/renderer/VertexArray.h"
#include "window.h"
#include "neko/Events/appE.h"
#include "layerstack.h"
#include "neko/imgui/imgui_layer.h"
#include "renderer/shader.h"
#include "renderer/Buffer.h"
#include "renderer/VertexArray.h"
#include <memory>
#include "neko/renderer/OrthographicCamera.h"

namespace NEKO
{
    class NekoApi Application {
        public:
           Application();
           ~Application();

           void run();
           void OnEvent(Event &e);
           void PushLayer(Layer *layer);
           void PushOverlay(Layer *layer);

           inline static Application &Get() {return *s_Instance; }
           inline Window &GetWindow() { return *m_Window; }
        private:
            bool OnWindowClose(WindowCloseEvent &e);
            bool OnWindowResized(WindowResizeEvent &e);
        private:
            std::unique_ptr<Window> m_Window;
            imgui_layer *m_imgui_layer;
            bool m_Running = true;
            LayerStack m_LayerStack;
            bool m_Minimized = false;

            float m_LastFrameTime = 0.0f;
        private:
            static Application *s_Instance;
    };

    // SandBox App side
    Application *CreateApplication();
}
