#pragma once

#include "NPCH.h"
#include "core.h"
#include "Events/Event.h"

namespace NEKO
{
    // Structure to hold properties for a window, such as title, width, and height.
    struct WindowProps {
        std::string Title;         // Window title.
        unsigned int Width;        // Window width.
        unsigned int Height;       // Window height.

        // Constructor with default values for title, width, and height.
        // This allows the window properties to be customized when the window is created.
        WindowProps(
            const std::string& title = "NEKO ENGINE", // Default title.
            unsigned int width = 1280,               // Default width.
            unsigned int height = 720)               // Default height.
            : Title(title), Width(width), Height(height)
        {
        }
    };

    // Base class for creating and managing windows.
    // This is an abstract class (interface), which means it only defines the interface
    // and expects derived classes to provide implementations for its pure virtual functions.
    class NekoApi Window {
    public:
        // Defines an alias for a function pointer type that takes an `Event&` as a parameter
        // and returns void. This will be used to pass event handling functions to the window.
        using EventCallbackFn = std::function<void(Event&)>;

        // Virtual destructor to ensure proper cleanup of derived classes.
        virtual ~Window() {}

        // Pure virtual method to update the window (to be implemented by derived classes).
        // This typically includes polling events, updating buffers, etc.
        virtual void OnUpdate() = 0;

        // Pure virtual methods to retrieve the window's width and height.
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // Window Attributes

        // Set the event callback function, which will be used to handle events such as window resizing,
        // key presses, etc. The derived classes must implement this.
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        // Set vertical sync (VSync) on or off. VSync controls the synchronization of the frame rate
        // with the monitor's refresh rate to prevent screen tearing.
        virtual void SetVsync(bool enabled) = 0;

        // Check if VSync is enabled.
        virtual bool IsVSync() const = 0;

        // Static factory method to create a window. This ensures that only one window can be created at a time.
        // It takes window properties (with default values) and returns a pointer to the created window.
        // The actual creation will be defined in platform-specific implementations (e.g., Windows, Linux).
        static Window* Create(const WindowProps& props = WindowProps());
    };
}
