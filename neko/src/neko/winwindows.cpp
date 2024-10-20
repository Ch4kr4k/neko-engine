#include "winwindows.h"

#include "GLFW/glfw3.h"
#include "NPCH.h"
#include "log.h"
#include "neko/Events/Event.h"
#include "neko/Events/appE.h"
#include "neko/Events/mouseE.h"
#include "neko/Events/keyE.h"
#include <X11/Xlib.h>

#include "glad/glad.h"
//#include "GLFW/glfw3.h"

namespace NEKO
{
    // Static variable to track if GLFW has been initialized. Ensures GLFW is initialized only once.
    static bool s_GLFWInitialized = false;

    static void GLFWerrorcallback(int error, const char* description)
    {
        NEKO_CORE_ERR("GLFW error");
    }
    // Factory method to create a new Window object. In this case, it creates a Windows-specific window.
    // It dynamically allocates memory for a WindowsWindow object and returns a pointer to it.
    Window* Window::Create(const WindowProps& props)
    {
        // Allocate a WindowsWindow instance using the provided window properties (title, width, height)
        return new WindowsWindow(props);
    }

    // Constructor for WindowsWindow: initializes the window with the given properties.
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props); // Calls the Init function to set up the window
    }

    // Destructor: Ensures the window is properly shut down when the object is destroyed.
    WindowsWindow::~WindowsWindow()
    {
        Shutdown(); // Calls the Shutdown function to clean up the GLFW window
    }

    // Initialization function: Sets up the window based on the properties (title, width, height)
    // passed in and initializes GLFW if it hasn't been initialized yet.
    void WindowsWindow::Init(const WindowProps& props)
    {
        // Store the window's properties in m_Data (title, dimensions)
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        // Log window creation using the core logger
        NEKO_CORE_INFO("Creating Window {0} ({1}, {2}) ", props.Title, props.Width, props.Height);

        // If GLFW hasn't been initialized yet, initialize it
        if (!s_GLFWInitialized)
        {
            int success = glfwInit(); // Initialize GLFW
            glfwSetErrorCallback(GLFWerrorcallback);
            s_GLFWInitialized = true; // Mark GLFW as initialized
        }

        // Create a GLFW window with the specified width, height, and title
        m_Window = glfwCreateWindow(
            (int)props.Width,
            (int)props.Height,
            m_Data.Title.c_str(),
            nullptr,   // No monitor specified (not fullscreen)
            nullptr    // No shared window context
        );

        // Make the created window's OpenGL context current
        glfwMakeContextCurrent(m_Window);

        // glad stuffs
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status) NEKO_CORE_ERR("Failed To Load GLAD");

        // Associate the m_Data structure with the GLFW window for future reference
        glfwSetWindowUserPointer(m_Window, &m_Data);

        // Enable VSync by default
        SetVsync(true);

        // Set GLFW CALL backs
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height)
        {
            NEKO_CORE_INFO("Resizing window: {0}x{1}", width, height);
            WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;
            WindowResizeEvent event(width, height);
            if (data.EventCallback) {
                data.EventCallback(event);
            } else {
                NEKO_CORE_ERR("EventCallback is null!");
            }
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
        {
           WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
           WindowCloseEvent event;
           data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch(action) {

                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }

                case GLFW_RELEASE:
                {
                    KeyReleased event(key);
                    data.EventCallback(event);
                    break;
                }

                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods)
        {
            WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                   MouseButtonPressed event(button);
                   data.EventCallback(event);
                   break;
                }

                case GLFW_RELEASE:
                {
                    MouseButtonReleased event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset)
        {
            WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int keycode)
        {
            WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

            KeyTyped event(keycode);
            data.EventCallback(event);
        });

    }

    // Function to properly shut down and destroy the GLFW window.
    void WindowsWindow::Shutdown()
    {
        // Destroy the GLFW window
        glfwDestroyWindow(m_Window);
    }

    // This function updates the window by polling for events (e.g., key presses, mouse movements)
    // and swapping the window's buffers to display the next frame.
    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();   // Process all pending window events (input, resize, etc.)
        glfwSwapBuffers(m_Window); // Swap the front and back buffers to display the rendered image
    }

    // Enables or disables vertical synchronization (VSync), which synchronizes the frame rate
    // with the monitor's refresh rate to prevent screen tearing.
    void WindowsWindow::SetVsync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1); // Enable VSync (1 means on)
        else
            glfwSwapInterval(0); // Disable VSync (0 means off)

        m_Data.VSync = enabled; // Store the VSync state in m_Data
    }

    // Returns whether VSync is currently enabled.
    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}
