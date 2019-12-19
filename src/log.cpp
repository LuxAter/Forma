#include "forma/log.hpp"

#include <iostream>
#include <memory>

#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

std::shared_ptr<spdlog::logger> forma::Log::s_core_logger;
std::shared_ptr<spdlog::logger> forma::Log::s_client_logger;

bool forma::Log::init() {
  try {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::trace);

    auto core_file_sink =
        std::make_shared<spdlog::sinks::daily_file_sink_mt>("log/forma", 23, 59);
    core_file_sink->set_level(spdlog::level::trace);
    auto client_file_sink=
        std::make_shared<spdlog::sinks::daily_file_sink_mt>("log/app", 23, 59);
    client_file_sink->set_level(spdlog::level::trace);

    s_core_logger = std::make_shared<spdlog::logger>(
        "FORMA", spdlog::sinks_init_list({console_sink, core_file_sink}));
    s_core_logger->set_level(spdlog::level::trace);
    s_client_logger = std::make_shared<spdlog::logger>(
        "APP", spdlog::sinks_init_list({console_sink, client_file_sink}));
    s_client_logger->set_level(spdlog::level::trace);
    spdlog::set_default_logger(s_core_logger);
    spdlog::set_level(spdlog::level::trace);
    return true;
  } catch (const spdlog::spdlog_ex &ex) {
    std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    return false;
  }
}
