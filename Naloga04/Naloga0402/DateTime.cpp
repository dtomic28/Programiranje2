//
// Created by danijel on 3/24/2024.
//

#include "DateTime.h"
#include <ctime>

const Date& DateTime::getDate() const
{
    return date;
}

void DateTime::setDate(const Date& date)
{
    DateTime::date = date;
}

const Time& DateTime::getTime() const
{
    return time;
}

void DateTime::setTime(const Time& time)
{
    DateTime::time = time;
}

DateTime::DateTime(const Date& date, const Time& time)
    : date(date)
    , time(time)
{
}

DateTime::DateTime(const DateTime& dateTime) = default;

unsigned int DateTime::toSeconds() const
{
    return date.getDaysSinceEpoch() * 24 * 60 * 60 + time.toSeconds();
}

std::string DateTime::toString() const
{
    return date.toString() + " " + time.toString();
}

DateTime DateTime::getCurrentDateTime()
{
    time_t now = std::time(nullptr);
    tm* currentTime = localtime(&now);
    Date currentDate(currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900);

    Time currentTimeObj(currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);

    return {currentDate, currentTimeObj};
}
