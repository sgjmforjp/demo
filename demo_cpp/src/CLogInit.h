//
// Created by vulko on 2023/3/13.
//

#ifndef DEMO_CPP_CLOGINIT_H
#define DEMO_CPP_CLOGINIT_H

#include "spdlog/spdlog.h"

class CLogInit {

public:
    static void init();
    static void free();
    static void set_level(const std::string& name, const std::string& level);

};

#define LOG_DEBUG(format, ...) \
    spdlog::get("debug_logger")->debug(FMT_STRING(format), ##__VA_ARGS__);

#define LOG_INFO(format, ...) \
    spdlog::get("info_logger")->info(FMT_STRING(format), ##__VA_ARGS__);

#define LOG_WARN(format, ...) \
    spdlog::get("warn_logger")->warn(FMT_STRING(format), ##__VA_ARGS__);

#define LOG_ERROR(format, ...) \
    spdlog::get("error_logger")->error(FMT_STRING(format), ##__VA_ARGS__);

#endif //DEMO_CPP_CLOGINIT_H
