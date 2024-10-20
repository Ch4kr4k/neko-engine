
#pragma once
#include "NPCH.h"
#include "neko/core.h"

namespace NEKO
{
    // Events in this system are blocking, meaning they are dispatched and handled immediately
    // as soon as they are triggered.

    // Enum class that defines all possible event types for the system.
    enum class EventType {
        None = 0,                    // Default case, no event.
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,   // App-level events.
        KeyPressed, KeyReleased,KeyTyped,         // Keyboard events.
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled // Mouse events.
    };

    // Event categories are defined using bit masks to allow multiple categories for a single event.
    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0), // Application-level events.
        EventCategoryInput = BIT(1), // Input-related events (e.g., keyboard, mouse).
        EventCategoryKeyboard = BIT(2), // Keyboard-specific events.
        EventCategoryMouse = BIT(3), // Mouse-specific events.
        EventCategoryMouseButton = BIT(4)  // Mouse button-specific events.
    };

    // Macro to define event type functions.
    // This macro implements three methods for a specific event type:
    // 1. `GetStaticType` returns the static event type.
    // 2. `GetEventType` is a virtual method that returns the event type (runtime).
    // 3. `GetName` returns the event name as a string.
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                virtual EventType GetEventType() const override { return GetStaticType(); }\
                                virtual const char* GetName() const override { return #type; }

    // Macro to define event category flags. This returns the category of an event.
    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

// Base class for all events.
// Pure virtual methods ensure that derived classes implement their specific behavior.
    class NekoApi Event {
        // Grant access to private members for the `EventDispatcher` class.
        friend class EventDispatcher;

    public:
        // Pure virtual method to get the event type. Must be implemented by derived classes.
        virtual EventType GetEventType() const = 0;

        // Pure virtual method to get the name of the event. Must be implemented by derived classes.
        virtual const char* GetName() const = 0;

        // Pure virtual method to get category flags. Must be implemented by derived classes.
        virtual int GetCategoryFlags() const = 0;

        // Provides a default string representation of the event using its name.
        virtual std::string ToString() const { return GetName(); }

        // Checks if an event belongs to a specific category by performing a bitwise AND.
        // If the result is non-zero, the event belongs to the category.
        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

        bool m_Handled = false;  // Tracks if the event has been handled.
    };

    // Dispatcher class for handling and dispatching events.
    // It uses templated functions to dispatch specific event types.
    class EventDispatcher {

        // Alias template for event handling functions. These functions return a bool
        // indicating whether the event was handled.
        template <typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        // Constructor that takes a reference to an event to be dispatched.
        EventDispatcher(Event& event)
            : m_Event(event)
        {}

        // Template function that dispatches the event if the type matches.
        // The function `func` is called if the event type matches the templated type `T`.
        template <typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                // If the event type matches, call the function and mark the event as handled.
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;  // Event type did not match, so no dispatch occurred.
        }

    private:
        Event& m_Event; // Reference to the event being dispatched.
    };

    // Overloaded stream insertion operator to easily print event details.
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();  // Outputs the event's string representation.
    }
}
