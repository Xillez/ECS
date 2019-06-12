#include "Logging.hpp"
#include "../config/Config.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <cxxabi.h>

const std::string Log::LOG_INFO = "INFO: ";
const std::string Log::LOG_WARN = "WARN: ";
const std::string Log::LOG_ERR = "ERR: ";

//static
void Log::Info(std::string msg, std::string callerName = "")
{
    if (LOGGING)
        if (callerName != "")
            std::cout << Log::LOG_INFO << msg << " - " << callerName << "\n";
        else
            std::cout << Log::LOG_INFO << msg << "\n";
}

//static
void Log::Warn(std::string msg, std::string callerName = "")
{
    if (LOGGING)
        if (callerName != "")
            std::cout << Log::LOG_WARN << msg << " - " << callerName << "\n";
        else
            std::cout << Log::LOG_WARN << msg << "\n";
}

//static
void Log::Err(std::string msg, std::string callerName = "")
{
    if (LOGGING)
        if (callerName != "")
            std::cout << Log::LOG_ERR << msg << " - " << callerName << "\n";
        else
            std::cout << Log::LOG_ERR << msg << "\n";
}