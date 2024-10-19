#include "NPCH.h"
#include "layerstack.h"


namespace NEKO
{
    LayerStack::LayerStack() { m_LayerInsert = m_Layers.begin(); }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers) delete layer;
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_Layers.emplace(m_Layers.begin(), layer);
        // m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.begin(), layer);
        if (it != m_Layers.begin())
        {
            //layer->OnDetach();
            m_Layers.erase(it);
            //m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
        if (it != m_Layers.end())
        {
            //overlay->OnDetach();
            m_Layers.erase(it);
        }
    }
}