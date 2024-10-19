#pragma once
#include "NPCH.h"
#include "Event.h"
#include "neko/core.h"

namespace NEKO
{
    // This class represents a window resize event. It inherits from the base `Event` class.
    // The event stores the new width and height of the window after resizing.
    class NekoApi WindowResizeEvent : public Event {
        public:
        // Constructor to initialize the window resize event with the new width and height.
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        // Getter for the new width of the window after resizing.
        inline unsigned int GetWidth() { return m_Width; }

        // Getter for the new height of the window after resizing.
        inline unsigned int GetHeight() { return m_Height; }

         // Overriding the `ToString()` method to return a string representation of the event.
        // This helps in debugging/logging by showing the width and height in a readable format.
        std::string ToString() const override
        {
                std::stringstream ss;
        ss << "WindowResizeEvent: " << m_Width << "x" << m_Height;
        return ss.str();
        }

		// Macro to define the static type for this event class, using the `WindowResize` event type.
		EVENT_CLASS_TYPE(WindowResize)

			// Macro to define the event category as an application event (e.g., window-related).
			EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height; // Stores the width and height after the window is resized.
	};

	// This class represents a window close event, signaling that the window is being closed.
	class WindowCloseEvent : public Event
	{
	public:
		// Default constructor.
		WindowCloseEvent() = default;

		// Macro to define the static type for this event class, using the `WindowClose` event type.
		EVENT_CLASS_TYPE(WindowClose)

			// Macro to define the event category as an application event.
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// This class represents a tick event in the application. It indicates that the app has ticked (usually for updating internal logic).
	class AppTickEvent : public Event
	{
	public:
		// Default constructor.
		AppTickEvent() = default;

		// Macro to define the static type for this event class, using the `AppTick` event type.
		EVENT_CLASS_TYPE(AppTick)

			// Macro to define the event category as an application event.
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// This class represents an application update event. It indicates that the application is updating (usually tied to game loops or rendering loops).
	class AppUpdateEvent : public Event
	{
	public:
		// Default constructor.
		AppUpdateEvent() = default;

		// Macro to define the static type for this event class, using the `AppUpdate` event type.
		EVENT_CLASS_TYPE(AppUpdate)

			// Macro to define the event category as an application event.
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// This class represents an application render event. It is triggered when the app needs to render (usually part of a render loop).
	class AppRenderEvent : public Event
	{
	public:
		// Default constructor.
		AppRenderEvent() = default;

		// Macro to define the static type for this event class, using the `AppRender` event type.
		EVENT_CLASS_TYPE(AppRender)

			// Macro to define the event category as an application event.
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
