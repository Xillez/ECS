#include "Logging.hpp"
#include "../config/Config.hpp"

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>

const std::string Log::LOG_INFO = "INFO";
const std::string Log::LOG_WARN = "WARN";
const std::string Log::LOG_ERR = "ERROR";
const std::string Log::LOG_DEBUG = "DEBUG";

//static
void Log::Info(std::string msg)
{
    if (LOGGING)
        std::printf("%s: %s\n", Log::LOG_INFO, msg);
}

//static
void Log::Warn(std::string msg)
{
    if (LOGGING)
        std::printf("%s: %s\n", Log::LOG_WARN, msg);
}

//static
void Log::Err(std::string msg)
{
    if (LOGGING)
        std::printf("%s: %s\n", Log::LOG_ERR, msg);
}

//static
void Log::Debug(std::string msg)
{
    if (LOGGING)
        std::printf("%s: %s\n", Log::LOG_DEBUG, msg);
}