#include "NPCH.h"
#include "layer.h"

namespace NEKO
{
    Layer::Layer(const std::string &debugName)
        : m_DebugName(debugName)
    {}

    Layer::~Layer() {}
}
