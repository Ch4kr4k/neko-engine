#pragma once
#include "NPCH.h"
#include "neko/core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"  // Necessary for custom formatting

namespace NEKO
{
    class NekoApi Log {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core logger macros
#define NEKO_CORE_ERR(...)   ::NEKO::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NEKO_CORE_INFO(...)  ::NEKO::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NEKO_CORE_WARN(...)  ::NEKO::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NEKO_CORE_TRACE(...) ::NEKO::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client logger macros
#define NEKO_ERR(...)   ::NEKO::Log::GetClientLogger()->error(__VA_ARGS__)
#define NEKO_INFO(...)  ::NEKO::Log::GetClientLogger()->info(__VA_ARGS__)
#define NEKO_WARN(...)  ::NEKO::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NEKO_TRACE(...) ::NEKO::Log::GetClientLogger()->trace(__VA_ARGS__)
