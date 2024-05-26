//
// Created by danijel on 5/26/2024.
//

#ifndef PROGRAMIRANJE2_LOG_H
#define PROGRAMIRANJE2_LOG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <experimental/source_location>

enum class LogType
{
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Log
{
private:
    std::ofstream file;
    std::string fileName = "log.txt";

    std::string getCurrentTime() const
    {
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);
        auto now_tm = *std::localtime(&now_time_t);

        std::ostringstream oss;
        oss << std::put_time(&now_tm, "%m/%d/%y %H:%M:%S");
        return oss.str();
    }

public:
    Log(LogType type, const std::experimental::source_location& loc = std::experimental::source_location::current())
    {
        file.open(fileName, std::ios_base::app);
        if (file.is_open())
        {
            file << getCurrentTime() << " " << logTypeToString(type) << " [" << loc.function_name() << "#" << loc.line() << "] ";
        }
    }

    ~Log()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    template <typename T>
    Log& operator<<(const T& msg)
    {
        if (file.is_open())
        {
            file << msg;
        }
        return *this;
    }

    static std::string logTypeToString(LogType type)
    {
        switch (type)
        {
            case LogType::DEBUG:
                return "DEBUG";
            case LogType::INFO:
                return "INFO";
            case LogType::WARN:
                return "WARN";
            case LogType::ERROR:
                return "ERROR";
            default:
                return "UNKNOWN";
        }
    }
};

#endif  // PROGRAMIRANJE2_LOG_H
