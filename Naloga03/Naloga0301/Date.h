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

public:
    void setDay(unsigned int day);

    void setMonth(unsigned int month);

    void setYear(unsigned int year);

private:
    static const int DaysInYear = 365;

public:
    Date(unsigned int day, unsigned int month, unsigned int year);
    Date();
    Date(const Date& date);

    std::string toString() const;

    static bool isLeapYear(unsigned int year);
    static unsigned int getDaysInMonth(unsigned int month, unsigned int year);
    static bool isDateValid(unsigned int day, unsigned int month, unsigned int year);
    static Date parse(const std::string& dateStr);
};

#endif  // PROGRAMIRANJE2_DATE_H
