#pragma once

#include "backends/imgui_impl_glfw.h"
#include "neko/renderer/GraphicsContext.h"
namespace NEKO
{
    class OpenGLContext : public GraphicsContext {
        public:
            OpenGLContext(GLFWwindow *windowHandle);

            virtual void Init() override;
            virtual void SwapBuffers() override;

        private:
            GLFWwindow *m_WindowHandle;
    };
}
