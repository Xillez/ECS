#pragma once
#include <string>

// ################################################################################################
// #                                                                                              #
// #                                           Logging                                            #
// #                                                                                              #
// ################################################################################################
 
/**
 * @brief Logger class. Logs is logging is enabled.
 */
class Log
{
public:
    /**
     * @brief Logs a message using the info tag.
     * 
     * @param msg - string - The message to print.
     * @param callerName - string - Name of caller function.
     */
    static void Info(std::string msg, std::string callerName);

    /**
     * @brief Logs a message using the warn tag.
     * 
     * @param msg - string - The message to print.
     * @param callerName - string - Name of caller function.
     */
    static void Warn(std::string msg, std::string callerName);

    /**
     * @brief Logs a message using the error tag.
     * 
     * @param msg - string - The message to print.
     * @param callerName - string - Name of caller function.
     */
    static void Err(std::string msg, std::string callerName);

    static const std::string LOG_INFO;
    static const std::string LOG_WARN;
    static const std::string LOG_ERR;

protected:
    //
private:
    //
};

#define LOG_INFO(msg) Log::Info((msg), __FUNCTION__)
#define LOG_WARN(msg) Log::Warn((msg), __FUNCTION__)
#define LOG_ERR(msg) Log::Err((msg), __FUNCTION__)