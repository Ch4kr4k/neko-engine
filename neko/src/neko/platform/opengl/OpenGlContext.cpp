#include "NPCH.h"
#include "OpenGlContext.h"
#include "backends/imgui_impl_glfw.h"
#include "neko/log.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace NEKO
{
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
        : m_WindowHandle(windowHandle)
    {
        if(!m_WindowHandle) NEKO_CORE_ERR("Window Handle is Null");
    }

    void OpenGLContext::Init()
    {
        // Make the created window's OpenGL context current
        glfwMakeContextCurrent(m_WindowHandle);
        // glad stuffs
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status) NEKO_CORE_ERR("Failed To Load GLAD");

        NEKO_CORE_INFO("GPU{0}", (char *)glGetString(GL_VENDOR) );
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }

}
