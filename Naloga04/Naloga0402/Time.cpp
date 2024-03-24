//
// Created by danijel on 3/24/2024.
//

#include "Time.h"
#include <sstream>
#include <iomanip>

unsigned int Time::getHours() const {
    return hours;
}

void Time::setHours(unsigned int hours) {
    Time::hours = hours;
}

unsigned int Time::getMinutes() const {
    return minutes;
}

void Time::setMinutes(unsigned int minutes) {
    Time::minutes = minutes;
}

unsigned int Time::getSeconds() const {
    return seconds;
}

void Time::setSeconds(unsigned int seconds) {
    Time::seconds = seconds;
}

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    if(isTimeValid(hours, minutes, seconds)){
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        return;
    }
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(const Time &time) = default;

std::string Time::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":" << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
    return oss.str();
}

bool Time::isTimeValid(unsigned int hours, unsigned int minutes, unsigned int seconds) {
    return (hours < 24) && (minutes < 60) && (seconds < 60);
}

unsigned int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}
