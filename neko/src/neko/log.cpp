#include "NPCH.h"
#include "log.h"

namespace NEKO
{
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");  // Time, logger name, message with color

        s_CoreLogger = spdlog::stderr_color_mt("NEKO");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stderr_color_mt("Client");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
