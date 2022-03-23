// @file: log.h
// @brief: glog or other log wrapper

#ifndef PERCEPTION_BASE_LOG_H_
#define PERCEPTION_BASE_LOG_H_

#include "glog/logging.h"

/******************************** USE GLOG ***********************************/
#define LOG_INFO LOG(INFO)
#define LOG_DEBUG DLOG(INFO)
#define LOG_WARN LOG(WARNING)
#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)
#define LOG_V(log_severity) VLOG(log_severity)

#define LOG_INFO_IF(cond) LOG_IF(INFO, cond)
#define LOG_ERROR_IF(cond) LOG_IF(ERROR, cond)

#define LOG_INFO_EVERY(freq) LOG_EVERY_N(INFO, freq)
#define LOG_WARN_EVERY(freq) LOG_EVERY_N(WARNING, freq)
#define LOG_ERROR_EVERY(freq) LOG_EVERY_N(ERROR, freq)

#define RETURN_IF_NULL(ptr)               \
    if (ptr == nullptr) {                 \
        LOG_WARN << #ptr << " is nullptr.";  \
        return;                           \
    }

#define RETURN_VAL_IF_NULL(ptr, val)      \
    if (ptr == nullptr) {                 \
        LOG_WARN << #ptr << " is nullptr.";  \
        return val;                       \
    }

#define RETURN_IF(condition)                   \
    if (condition) {                           \
        LOG_WARN << #condition << " is not met."; \
        return;                                \
    }

#define RETURN_VAL_IF(condition, val)          \
    if (condition) {                           \
        LOG_WARN << #condition << " is not met."; \
        return val;                            \
    }

#define GLOG_TIMESTAMP(timestamp)              \
    std::to_string(timestamp)

#endif  // PERCEPTION_BASE_LOG_H_
