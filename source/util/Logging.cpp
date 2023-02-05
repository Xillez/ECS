#include "Logging.hpp"
#include "../config/Config.hpp"

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

const std::string Log::LOG_INFO = "INFO";
const std::string Log::LOG_WARN = "WARN";
const std::string Log::LOG_ERR = "ERROR";
const std::string Log::LOG_DEBUG = "DEBUG";

const std::vector<std::string> Log::LOGGING_LEVELS = LOGGING_LEVEL;

//static
void Log::Info(std::string msg)
{
    Log::LogMsg(Log::LOG_INFO, msg);
}

//static
void Log::Warn(std::string msg)
{
    Log::LogMsg(Log::LOG_WARN, msg);
}

//static
void Log::Err(std::string msg)
{
    Log::LogMsg(Log::LOG_ERR, msg);
}

//static
void Log::Debug(std::string msg)
{
    Log::LogMsg(Log::LOG_DEBUG, msg);
}

//static
void Log::LogMsg(std::string tag, std::string msg)
{
    if (
        LOGGING && 
        std::find(Log::LOGGING_LEVELS.begin(), Log::LOGGING_LEVELS.end(), tag) != Log::LOGGING_LEVELS.end()
    )
        std::cout << tag << ": " << msg << std::endl;
}

//static
void Log::LogMsg(std::string tag, char* msg)
{
    if (
        LOGGING && 
        std::find(Log::LOGGING_LEVELS.begin(), Log::LOGGING_LEVELS.end(), tag) != Log::LOGGING_LEVELS.end()
    )
        std::cout << tag << ": " << msg << std::endl;
}