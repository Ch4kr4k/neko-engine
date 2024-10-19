#pragma once
#include "NPCH.h"
#include "Event.h"
#include "neko/core.h"

namespace NEKO
{
	// Represents the event when the mouse is moved.
	class NekoApi MouseMovedEvent : public Event {

		public:
			// Constructor to initialize the mouse position (x, y) where the event occurred.
			MouseMovedEvent(float x, float y)
				: m_MouseX(x), m_MouseY(y)
			{}

			// Getter for the X-coordinate of the mouse position.
			inline float GetX() const { return m_MouseX; }

			// Getter for the Y-coordinate of the mouse position.
			inline float GetY() const { return m_MouseY; }

			// Overridden `ToString()` method to create a human-readable representation of the event,
			// showing the mouse coordinates (x, y).
			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
				return ss.str();
			}

			// Macro defining this event as `MouseMoved`.
			EVENT_CLASS_TYPE(MouseMoved)

			// This event belongs to both the Mouse and Input categories.
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		private:
			// Coordinates of the mouse when the event occurred.
			float m_MouseX, m_MouseY;
	};

	// Represents the event when the mouse wheel is scrolled.
	class NekoApi MouseScrolledEvent : public Event {

		public:
			// Constructor that initializes the horizontal and vertical scroll offsets.
			MouseScrolledEvent(float xOffset, float yOffset)
				: m_XOffset(xOffset), m_YOffset(yOffset)
			{}

			// Getter for the horizontal scroll offset.
			inline float GetXOffset() const { return m_XOffset; }

			// Getter for the vertical scroll offset.
			inline float GetYOffset() const { return m_YOffset; }

			// Overridden `ToString()` method to provide a string representation of the scroll event.
			// Shows both the horizontal and vertical scroll offsets.
			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
				return ss.str();
			}

			// Macro defining this event as `MouseScrolled`.
			EVENT_CLASS_TYPE(MouseScrolled)

			// This event belongs to both the Mouse and Input categories.
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		private:
			// The horizontal scroll offset (positive/negative values represent right/left scrolls).
			float m_XOffset;

			// The vertical scroll offset (positive/negative values represent up/down scrolls).
			float m_YOffset;
	};

	// Base class for mouse button events.
	// It handles both mouse button press and release events.
	class NekoApi MouseButtonEvent : public Event {

		public:
			// Getter for the mouse button that triggered the event.
			inline int GetMouseButton() const { return m_Button; }

			// This event belongs to both the Mouse and Input categories.
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		protected:
			// Constructor that takes the button code (which button was pressed/released).
			MouseButtonEvent(int button)
				: m_Button(button) {}

			// Stores the button code (left, right, middle, etc.).
			int m_Button;
	};

	// Represents the event when a mouse button is pressed.
	class NekoApi MouseButtonPressed : public MouseButtonEvent {

		public:
			// Constructor that takes the button code (which button was pressed).
			MouseButtonPressed(int button)
				: MouseButtonEvent(button) {}

			// Overridden `ToString()` method to provide a string representation of the event,
			// showing which mouse button was pressed.
			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				return ss.str();
			}

			// Macro defining this event as `MouseButtonPressed`.
			EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	// Represents the event when a mouse button is released.
	class NekoApi MouseButtonReleased : public MouseButtonEvent {

		public:
			// Constructor that takes the button code (which button was released).
			MouseButtonReleased(int button)
				: MouseButtonEvent(button) {}

			// Overridden `ToString()` method to provide a string representation of the event,
			// showing which mouse button was released.
			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << m_Button;
				return ss.str();
			}

			// Macro defining this event as `MouseButtonReleased`.
			EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
