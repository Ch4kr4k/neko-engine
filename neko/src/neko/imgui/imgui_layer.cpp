#include "NPCH.h"

//#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "imgui.h"

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include "imgui_layer.h"
#include "neko/app.h"
#include <X11/X.h>

namespace NEKO
{
    imgui_layer::imgui_layer()
        : Layer("imgui") {}

    imgui_layer::~imgui_layer(){}

    void imgui_layer::OnAttach()
    {
       IMGUI_CHECKVERSION();
       ImGui::CreateContext();
       ImGuiIO &io = ImGui::GetIO(); (void)io;

       io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
       io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
       io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

       ImGui::StyleColorsDark();

       ImGuiStyle &style = ImGui::GetStyle();

       if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
           style.WindowRounding = 1.0f;
           style.Colors[ImGuiCol_WindowBg].w = 1.0f;
       }

       Application &app = Application::Get();
       GLFWwindow *window = static_cast<GLFWwindow *>(app.GetWindow().GetNativeWindow());

       ImGui_ImplGlfw_InitForOpenGL(window, true);
       ImGui_ImplOpenGL3_Init("#version 410");
    }

    void imgui_layer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void imgui_layer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void imgui_layer::End()
    {
        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::Get();
        io.DisplaySize = ImVec2( app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void imgui_layer::OnImGuiRender()
    {
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
    }

}
