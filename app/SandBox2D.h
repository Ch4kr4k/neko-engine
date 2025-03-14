#pragma once

#include "neko.h"
#include <glm/fwd.hpp>

class Sandbox2D : public NEKO::Layer {
    public:
        Sandbox2D();
        virtual ~Sandbox2D() = default;
        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void OnUpdate(NEKO::Timestep ts) override;
        virtual void OnImGuiRender() override;
        void OnEvent(NEKO::Event &e) override;

    private:
        NEKO::OrthographicCameraController m_CameraController;

        // TEMP
        NEKO::Ref<NEKO::VertexArray> m_SquareVA;
        NEKO::Ref<NEKO::Shadder> m_FlatColorShader;
        NEKO::Ref<NEKO::Texture2D> m_Texture;
        glm::vec4 m_SquareColor = {0.2f, 0.3f, 0.8f, 1.0f};

};
