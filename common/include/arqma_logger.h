#pragma once

#include "spdlog/spdlog.h"

#define ARQMA_LOG_N(LVL, msg, ...)                                              \
    spdlog::get("arqma_logger")->LVL("[{}] " msg, __func__, __VA_ARGS__)
#define ARQMA_LOG_2(LVL, msg)                                                   \
    spdlog::get("arqma_logger")->LVL("[{}] " msg, __func__);

#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, NAME, ...) NAME
#define ARQMA_LOG(...)                                                          \
    GET_MACRO(__VA_ARGS__, ARQMA_LOG_N, ARQMA_LOG_N, ARQMA_LOG_N, ARQMA_LOG_N,     \
              ARQMA_LOG_N, ARQMA_LOG_N, ARQMA_LOG_N, ARQMA_LOG_2)                  \
    (__VA_ARGS__)

namespace arqma {
using LogLevelPair = std::pair<std::string, spdlog::level::level_enum>;
using LogLevelMap = std::vector<LogLevelPair>;
using LogLevel = spdlog::level::level_enum;
// clang-format off
static const LogLevelMap logLevelMap{
    {"trace", LogLevel::trace},
    {"debug", LogLevel::debug},
    {"info", LogLevel::info},
    {"warning", LogLevel::warn},
    {"error", LogLevel::err},
    {"critical", LogLevel::critical}
};
// clang-format on

void init_logging(const std::string& data_dir, LogLevel log_level);

void print_log_levels();

bool parse_log_level(const std::string& input, LogLevel& logLevel);
} // namespace arqma
