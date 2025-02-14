#pragma once

//#include "Assert.h"
#include "neko/renderer/shader.h"
#include <memory>
#define NekoApi __attribute__((visibility("default")))
#define BIT(x) (1 << x)
#define NEKO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace NEKO
{
    template<typename T>
    using Scope = std::unique_ptr<T>;

    template <typename T>
    using Ref = std::shared_ptr<T>;
}
