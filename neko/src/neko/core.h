#pragma once

#define NekoApi __attribute__((visibility("default")))
#define BIT(x) (1 << x)
#define NEKO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
