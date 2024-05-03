//
// Created by danijel on 3/16/2024.
//

#ifndef PROGRAMIRANJE2_DATE_H
#define PROGRAMIRANJE2_DATE_H
#include <string>

class Date
{
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    constexpr static const int MaxDayByMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static const int MaxMonth = 12;
    static const int DaysInYear = 365;

public:
    void setDay(unsigned int day);

    void setMonth(unsigned int month);

    void setYear(unsigned int year);

public:
    Date(unsigned int day, unsigned int month, unsigned int year);
    Date();
    Date(const Date& date);

    std::string toString() const;
    unsigned int getDaysSinceEpoch() const;

    static bool isLeapYear(unsigned int year);
    static unsigned int getDaysInMonth(unsigned int month, unsigned int year);
    static bool isDateValid(unsigned int day, unsigned int month, unsigned int year);
    static Date parse(const std::string& dateStr);

    bool operator<(const Date& other) const
    {
        if (year < other.year)
        {
            return true;
        }
        else if (year == other.year && month < other.month)
        {
            return true;
        }
        else if (year == other.year && month == other.month && day < other.day)
        {
            return true;
        }
        return false;
    }

    bool operator>(const Date& other) const
    {
        return !(*this < other || *this == other);
    }

    bool operator<=(const Date& other) const
    {
        return (*this < other || *this == other);
    }

    bool operator>=(const Date& other) const
    {
        return !(*this < other);
    }

    bool operator==(const Date& other) const
    {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date& other) const
    {
        return !(*this == other);
    }

    static Date getCurrentDate();
};

#endif  // PROGRAMIRANJE2_DATE_H
