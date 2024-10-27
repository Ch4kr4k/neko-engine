#pragma once
#include "core.h"
#include <iostream>
#include <utility>
namespace NEKO
{
    class NekoApi Input {
        public:
            inline static bool IsKeyPressed( int KeyCode) { return s_Instances->IsKeyPressedImpl(KeyCode); }

            inline static bool IsMouseButtonPressed(int button) { return s_Instances->IsButtonPressedImpl(button); }
            inline static float GetMouseX() { return s_Instances->GetMouseXImpl();}
            inline static float GetMouseY() { return s_Instances->GetMouseYImpl();}
            inline static std::pair<float, float> GetMousePos() {return s_Instances->GetMousePosImpl();}
        protected:
            virtual bool IsKeyPressedImpl(int KeyCode) = 0;

            virtual bool IsButtonPressedImpl(int button) = 0;
            virtual float GetMouseXImpl() = 0;
            virtual float GetMouseYImpl() = 0;
            virtual std::pair<float, float> GetMousePosImpl() = 0;

        private:
            static Input *s_Instances;
    };
}
