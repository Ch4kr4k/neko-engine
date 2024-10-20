#pragma once

#include "core.h"
#include "Events/Event.h"
#include "window.h"
#include "neko/Events/appE.h"
#include "layerstack.h"

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
            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
            LayerStack m_LayerStack;
        private:
            static Application *s_Instance;
    };

    // SandBox App side
    Application *CreateApplication();
}
