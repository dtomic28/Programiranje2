//
// Created by danijel on 3/24/2024.
//

#ifndef PROGRAMIRANJE2_DATETIME_H
#define PROGRAMIRANJE2_DATETIME_H
#include "Date.h"
#include "Time.h"

class DateTime {
public:
    Date date;
    Time time;

    DateTime(const Date& date, const Time& time);
    DateTime(const DateTime &dateTime);

    const Date &getDate() const;

    void setDate(const Date &date);

    const Time &getTime() const;

    void setTime(const Time &time);

    unsigned int toSeconds() const;
    std::string toString() const;

    static DateTime getCurrentDateTime();

    bool operator<(const DateTime& other) const {
        if (date < other.date) {
            return true;
        } else if (date == other.date && time < other.time) {
            return true;
        }
        return false;
    }

    bool operator>(const DateTime& other) const {
        return !(*this < other || *this == other);
    }

    bool operator<=(const DateTime& other) const {
        return (*this < other || *this == other);
    }

    bool operator>=(const DateTime& other) const {
        return !(*this < other);
    }

    bool operator==(const DateTime& other) const {
        return date == other.date && time == other.time;
    }

    bool operator!=(const DateTime& other) const {
        return !(*this == other);
    }
};


#endif //PROGRAMIRANJE2_DATETIME_H
