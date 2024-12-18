#include "neko.h"
#include "neko/Events/Event.h"
#include "neko/keycodes.h"
#include "neko/log.h"
#include "imgui.h"

class ex_layer : public NEKO::Layer {
    public:
        ex_layer()
            : Layer("ex's")
        {

        }

    void OnUpdate() override
    {
        if(NEKO::Input::IsKeyPressed(NEKO_KEY_TAB)) NEKO_TRACE("Tab Key Is Pressed");
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Tiyangsen Lemtur");
        ImGui::End();
    }
};

class SboxApp : public NEKO::Application{
    public:
        SboxApp()
        {
            PushLayer(new ex_layer());
            // PushOverlay(new NEKO::imgui_layer);
        }

        ~SboxApp()
        {

        }
};

NEKO::Application *NEKO::CreateApplication()
{
    return new SboxApp();
}
