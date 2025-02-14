#pragma once

namespace NEKO
{
    class Timestep {
        public:
            Timestep(float _time = 0)
                : m_Time(_time)
            {
            }

        operator float() const { return m_Time; }

        float GetSeconds() const { return m_Time; }
        float GetMilliseconds() const { return m_Time * 1000.0f; }
        private:
            float m_Time;
    };

}
