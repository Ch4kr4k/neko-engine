#pragma once

#include "neko/log.h"
#include <glm/fwd.hpp>
#include <glm/glm.hpp>

namespace NEKO
{
    class OrthographicCamera{
        public:
            OrthographicCamera(float left, float right, float bottom, float top);
            void SetProjection(float left, float right, float bottom, float top);

            const glm::vec3 &GetPosition() const {return m_Position;}
            void SetPosition(const glm::vec3& position) { m_Position = position; ReCalculateViewMatrix(); }

            float GetRotation() const {return m_Rotation;}
            void SetRotation(float rotation) { m_Rotation = rotation; ReCalculateViewMatrix(); }


            const glm::mat4 &GetProjectionMatrix() const {return m_ProjectionMatrix;}
            const glm::mat4 &GetViewMatrix() const {return m_ViewMatrix;}
            const glm::mat4 &GetViewProjectMatrix() const {return m_ViewProjectionMatrix; }

        private:
            void ReCalculateViewMatrix();
        private:
            glm::mat4 m_ProjectionMatrix;
            glm::mat4 m_ViewMatrix;
            glm::mat4 m_ViewProjectionMatrix;

            glm::vec3 m_Position = {0.0f, 0.0f, 0.0f};
            float m_Rotation = 0.0f;
    };

}
