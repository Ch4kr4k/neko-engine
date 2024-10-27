#pragma once

#include "neko/input.h"

namespace NEKO
{
    class WindowsInput : public Input {
        protected:
            virtual bool IsKeyPressedImpl(int KeyCode) override;

            virtual bool IsButtonPressedImpl(int button) override;
            virtual float GetMouseXImpl() override;
            virtual float GetMouseYImpl() override;
            virtual std::pair<float, float> GetMousePosImpl() override;
    };
}
