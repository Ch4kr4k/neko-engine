#include "neko.h"
#include "neko/Events/Event.h"
#include "neko/imgui/imgui_layer.h"
#include "neko/layer.h"

class ex_layer : public NEKO::Layer {
    public:
        ex_layer()
            : Layer("ex's")
        {

        }

    void OnUpdate() override
    {

    }

    void OnEvent(NEKO::Event &event) override
    {

    }
};

class SboxApp : public NEKO::Application{
    public:
        SboxApp()
        {
            PushOverlay(new NEKO::imgui_layer);
        }

        ~SboxApp()
        {

        }
};

NEKO::Application *NEKO::CreateApplication()
{
    return new SboxApp();
}
