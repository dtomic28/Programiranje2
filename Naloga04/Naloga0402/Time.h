//
// Created by danijel on 3/24/2024.
//

#ifndef PROGRAMIRANJE2_TIME_H
#define PROGRAMIRANJE2_TIME_H
#include <string>

class Time {
private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
public:
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds);
    Time();
    Time(const Time &time);

    [[nodiscard]] unsigned int getHours() const;
    [[nodiscard]] unsigned int getMinutes() const;
    [[nodiscard]] unsigned int getSeconds() const;

    void setHours(unsigned int hours);
    void setMinutes(unsigned int minutes);
    void setSeconds(unsigned int seconds);

    [[nodiscard]] std::string toString() const;
    [[nodiscard]] unsigned int toSeconds() const;
    static bool isTimeValid(unsigned int hours, unsigned int minutes, unsigned int seconds);

    bool operator<(const Time& other) const {
        if (hours < other.hours) {
            return true;
        } else if (hours == other.hours && minutes < other.minutes) {
            return true;
        } else if (hours == other.hours && minutes == other.minutes && seconds < other.seconds) {
            return true;
        }
        return false;
    }

    bool operator>(const Time& other) const {
        return !(*this < other || *this == other);
    }

    bool operator<=(const Time& other) const {
        return (*this < other || *this == other);
    }

    bool operator>=(const Time& other) const {
        return !(*this < other);
    }

    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }
};


#endif //PROGRAMIRANJE2_TIME_H
