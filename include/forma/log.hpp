#ifndef FORMA_LOG_HPP_
#define FORMA_LOG_HPP_

#include <cstdlib>
#include <iostream>
#include <string>

#ifdef __DEBUG__
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#define TRACE(...) SPDLOG_LOGGER_TRACE(::forma::Log::get_client(), __VA_ARGS__)
#define INFO(...) SPDLOG_LOGGER_INFO(::forma::Log::get_client(), __VA_ARGS__)
#define WARN(...) SPDLOG_LOGGER_WARN(::forma::Log::get_client(), __VA_ARGS__)
#define ERROR(...) SPDLOG_LOGGER_ERROR(::forma::Log::get_client(), __VA_ARGS__)
#define CRITICAL(...)                                                          \
  SPDLOG_LOGGER_CRITICAL(::forma::Log::get_client(), __VA_ARGS__)

#define LTRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define LINFO(...) SPDLOG_INFO(__VA_ARGS__)
#define LWARN(...) SPDLOG_WARN(__VA_ARGS__)
#define LERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define LCRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)

namespace forma {
class Log {
public:
  static bool init();
  inline static std::shared_ptr<spdlog::logger> get_core() {
    return s_core_logger;
  }
  inline static std::shared_ptr<spdlog::logger> get_client() {
    return s_client_logger;
  }
  template <typename... _ARGS>
  inline static void trace(std::string fmt, const _ARGS &... args) {
    spdlog::trace(fmt, args...);
  }
  template <typename... _ARGS>
  inline static void debug(std::string fmt, const _ARGS &... args) {
    spdlog::debug(fmt, args...);
  }
  template <typename... _ARGS>
  inline static void info(std::string fmt, const _ARGS &... args) {
    spdlog::info(fmt, args...);
  }
  template <typename... _ARGS>
  inline static void warn(std::string fmt, const _ARGS &... args) {
    spdlog::warn(fmt, args...);
  }
  template <typename... _ARGS>
  inline static void error(std::string fmt, const _ARGS &... args) {
    spdlog::error(fmt, args...);
  }
  template <typename... _ARGS>
  inline static void critical(std::string fmt, const _ARGS &... args) {
    spdlog::critical(fmt, args...);
  }

private:
  static std::shared_ptr<spdlog::logger> s_core_logger;
  static std::shared_ptr<spdlog::logger> s_client_logger;
};
} // namespace forma

#endif // FORMA_LOG_HPP_
