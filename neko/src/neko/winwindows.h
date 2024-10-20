#pragma once

#define GLFW_INCLUDE_NONE
#include "window.h"
#include <GLFW/glfw3.h>

namespace NEKO
{
    // WindowsWindow class inherits from the base Window class and provides an implementation
    // specific to the Windows platform using GLFW.
    class WindowsWindow : public Window {

    public:
        // Constructor: Initializes the window with the specified properties.
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        // Function to keep updating the window (e.g., polling events, rendering, etc.).
        void OnUpdate() override;

        // Returns the current width of the window.
        inline unsigned int GetWidth() const override { return m_Data.Width; }

        // Returns the current height of the window.
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        // Sets the event callback function pointer. This function is used to process events
        // such as window resizing, key presses, etc., by passing the event to the callback.
        inline void SetEventCallback(const EventCallbackFn& callback) override
        {
            m_Data.EventCallback = callback;
        }

        // Enables or disables VSync (vertical synchronization).
        void SetVsync(bool enabled) override;

        // Checks whether VSync is enabled or not.
        bool IsVSync() const override;

        // Returns the native GLFW window object (useful for lower-level operations).
        virtual void* GetNativeWindow() const { return m_Window; }

    private:
        // Initializes the window with the specified properties (like title, width, height, etc.)
        virtual void Init(const WindowProps& props);

        // Cleans up and destroys the window when no longer needed.
        virtual void Shutdown();

    private:
        // Pointer to the GLFW window object.
        GLFWwindow* m_Window;

        // Structure to hold window-related data such as title, size, VSync state, and the
        // event callback function for processing window events.
        struct WindowData
        {
            std::string Title;          // Window title
            unsigned int Width, Height; // Window dimensions
            bool VSync;                 // VSync enabled/disabled

            // Function pointer to the event callback. This is a std::function that processes events.
            EventCallbackFn EventCallback;
        };

        // Instance of WindowData to store the current window's state.
        WindowData m_Data;

    };

    static void GLFWerrorcallback(int error, const char* description);
}
