#pragma once
#include "NPCH.h"
#include "Event.h"

namespace NEKO
{
	// Base class for all keyboard-related events.
	// Inherits from the Event class and stores the keycode for the event.
	class NekoApi KeyEvent : public Event {
		public:
			// Getter for the key code (key that was pressed/released).
			inline int GetKeyCode() const { return m_KeyCode; }

			// Macro that defines this event as belonging to both the Keyboard and Input categories.
			EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		protected:
			// Protected constructor to ensure that `KeyEvent` can only be created through derived classes.
			// Takes a keycode as a parameter (the code of the key involved in the event).
			KeyEvent(int keycode)
				: m_KeyCode(keycode) {}

			// Stores the key code of the key pressed or released.
			int m_KeyCode;
	};

	// Represents a key press event.
	// Inherits from KeyEvent and adds functionality for handling repeat counts (useful for keys being held down).
	class NekoApi KeyPressedEvent : public KeyEvent {

		public:
			// Constructor that takes the keycode and repeat count (how many times the key was pressed).
			KeyPressedEvent(int keycode, int repeatCount)
				: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

			// Getter for the repeat count (number of times the key is repeated, typically when held down).
			inline int GetRepeatCount() const { return m_RepeatCount; }

			// Overridden `ToString()` method to give a human-readable representation of the event, showing the keycode and repeat count.
			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " Repeats)";
				return ss.str();
			}

			// Static method to return the event type (KeyPressed). This allows for checking the specific type of event at runtime.
			//static EventType GetStaticType() { return EventType::KeyPressed; }

			// Overridden method to return the event type for this specific instance.
			//virtual EventType GetEventType() const override { return GetStaticType(); }

			// Overridden method to return the name of the event as a string (useful for debugging/logging).
			//virtual const char* GetName() const override { return "KeyPressed"; }

			// Macro to define the type of this event as `KeyPressed`.
			EVENT_CLASS_TYPE(KeyPressed)

		private:
			// Stores the repeat count for the key press event.
			// This is the number of times the key press is registered when the key is held down.
			int m_RepeatCount;

	};

	// Represents a key release event.
	// Inherits from KeyEvent and is used when a key is released.
	class NekoApi KeyReleased : public KeyEvent {

		public:
			// Constructor that takes the keycode of the key that was released.
			KeyReleased(int keycode)
				: KeyEvent(keycode) {}

			// Overridden `ToString()` method to give a human-readable representation of the event, showing the keycode of the released key.
			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyReleased: " << m_KeyCode;
				return ss.str();
			}

			// Macro to define the type of this event as `KeyReleased`.
			EVENT_CLASS_TYPE(KeyReleased)
	};

	class NekoApi KeyTyped : public KeyEvent {

		public:
			// Constructor that takes the keycode and repeat count (how many times the key was pressed).
			KeyTyped(int keycode)
				: KeyEvent(keycode){}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyTyped: " << m_KeyCode;
				return ss.str();
			}
			EVENT_CLASS_TYPE(KeyPressed)
	};

}
