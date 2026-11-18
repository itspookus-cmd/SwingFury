#include "pch.h"

#include <spdlog/sinks/basic_file_sink.h>

namespace
{
    void SetupLog()
    {
        const auto logDirectory = SKSE::log::log_directory();
        if (!logDirectory) {
            SKSE::stl::report_and_fail("SwingFury: SKSE did not provide a log directory.");
            return;
        }

        std::error_code ec;
        std::filesystem::create_directories(*logDirectory, ec);

        const auto logPath = *logDirectory / "SwingFury.log";
        auto logger = spdlog::basic_logger_mt("SwingFury", logPath.string(), true);
        logger->set_level(spdlog::level::info);
        logger->set_pattern("[%H:%M:%S] [%l] %v");
        logger->flush_on(spdlog::level::info);
        spdlog::set_default_logger(std::move(logger));
    }
}

// CommonLibSSE-NG exports the correctly named SKSEPlugin_Load entry point.
SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
    SetupLog();
    logs::info("SwingFury load entry point reached.");

    SKSE::Init(a_skse);
    logs::info("SwingFury loaded successfully.");

    return true;
}
