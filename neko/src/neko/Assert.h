#include "log.h"
#include <filesystem>

#define NEKO_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { NEKO##type##ERR(msg, __VA_ARGS__); } }
#define NEKO_INTERNAL_ASSERT_WITH_MSG(type, check, ...) NEKO_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define NEKO_INTERNAL_ASSERT_NO_MSG(type, check) NEKO_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", NEKO_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define NEKO_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define NEKO_INTERNAL_ASSERT_GET_MACRO(...) NEKO_EXPAND_MACRO( NEKO_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, NEKO_INTERNAL_ASSERT_WITH_MSG, NEKO_INTERNAL_ASSERT_NO_MSG)  )

#define NEKO_ASSERT(...) NEKO_EXPAND_MACRO( NEKO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__)  )
#define NEKO_CORE_ASSERT(...) NEKO_EXPAND_MACRO( NEKO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__)  )
