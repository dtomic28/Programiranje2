#include "Time.h"

Time::Time()
    : hours(0)
    , minutes(0)
    , seconds(0)
{
}

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
    if (hours < 24 && minutes < 60 && seconds < 60)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }
    else
    {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }
}

Time::Time(const Time& time)
    : hours(time.hours)
    , minutes(time.minutes)
    , seconds(time.seconds)
{
}

unsigned int Time::getHours() const
{
    return hours;
}

void Time::setHours(unsigned int hours)
{
    Time::hours = hours;
}

unsigned int Time::getMinutes() const
{
    return minutes;
}

void Time::setMinutes(unsigned int minutes)
{
    Time::minutes = minutes;
}

unsigned int Time::getSeconds() const
{
    return seconds;
}

void Time::setSeconds(unsigned int seconds)
{
    Time::seconds = seconds;
}

std::string Time::toString() const
{
    std::string str = "";
    int size = 3;
    unsigned int numbers[] = {hours, minutes, seconds};
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] < 10)
            str += "0";
        str += std::to_string(numbers[i]);
        if (i < size - 1)
            str += ":";
    }
    return str;
}

unsigned int Time::toSeconds() const
{
    return seconds + minutes * 60 + hours * 60 * 60;
}
