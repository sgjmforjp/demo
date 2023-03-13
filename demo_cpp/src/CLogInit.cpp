//
// Created by vulko on 2023/3/13.
//

#include "CLogInit.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/async.h"

void CLogInit::init() {

    std::locale::global(std::locale("en_US.UTF-8"));

    spdlog::init_thread_pool(8192, 4);
    spdlog::set_level(spdlog::level::info);
    spdlog::flush_every(std::chrono::seconds(3));
    spdlog::flush_on(spdlog::level::info);

    auto debug = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/debug.log", 1024 * 1024 * 1, 3);
    auto debug_logger = std::make_shared<spdlog::async_logger>("debug_logger", debug, spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    debug_logger->set_level(spdlog::level::debug);
    debug_logger->set_pattern("[%H:%M:%S %z] %v");
    spdlog::register_logger(debug_logger);

    //info 日志
    auto console = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto info = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/info.log", 9, 30);
    std::vector<spdlog::sink_ptr> info_list {console, info};
    auto info_logger = std::make_shared<spdlog::async_logger>("info_logger", std::begin(info_list), std::end(info_list), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    info_logger->set_pattern("[%H:%M:%S %z] %v");
    info_logger->set_level(spdlog::level::info);
    spdlog::register_logger(info_logger);

    //warn 日志
    auto warn = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/warn.log", 9, 30);
    std::vector<spdlog::sink_ptr> warn_list {console, warn};
    auto warn_logger = std::make_shared<spdlog::async_logger>("warn_logger", std::begin(warn_list), std::end(warn_list), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    warn_logger->set_pattern("[%H:%M:%S %z] %v");
    warn_logger->set_level(spdlog::level::warn);
    spdlog::register_logger(warn_logger);

    //error 日志
    auto error = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/error.log", 9, 30);
    std::vector<spdlog::sink_ptr> error_list {console, error};
    auto error_logger = std::make_shared<spdlog::async_logger>("error_logger", std::begin(error_list), std::end(error_list), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
    error_logger->set_pattern("[%H:%M:%S %z] %v");
    error_logger->set_level(spdlog::level::err);
    spdlog::register_logger(error_logger);

    LOG_DEBUG("This is a {} test", "debug");
    LOG_INFO("This is a {} test", "info");
    LOG_WARN("This is a {} test", "warn");
    LOG_ERROR("This is a {} test", "error");

}

void CLogInit::free() {
// 程序退出前清理
    spdlog::drop_all();
}

void CLogInit::set_level(const std::string &name, const std::string &level) {
    auto logger = spdlog::get(name);
    auto lvl = spdlog::level::from_str(level);
    if (logger && lvl != spdlog::level::off) {
        logger->set_level(lvl);
        fmt::print("[{}] set_level to : {}\n", name, level);
    }
}
