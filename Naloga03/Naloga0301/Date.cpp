//
// Created by danijel on 3/16/2024.
//

#include "Date.h"
#include <string>

Date::Date(unsigned int day,unsigned int month, unsigned int year) {
    if(isDateValid(day, month, year)){
        this->day = day;
        this->month = month;
        this->year = year;
    }else{
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }
}

Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1970;
}

Date::Date(const Date &date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

std::string Date::toString() const {
    return std::to_string(this->day) + "." + std::to_string(this->month) + "." + std::to_string(this->year);
}

bool Date::isLeapYear(unsigned int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

unsigned int Date::getDaysInMonth(unsigned int month, unsigned int year) {
    if(month < 1 || month > MaxMonth)
        return 0;

    if(month == 2 && isLeapYear(year))
        return 29;


    return MaxDayByMonth[month-1];
}

bool Date::isDateValid(unsigned int day, unsigned int month, unsigned int year) {
    if(year < 1970)
        return false;

    if(month <= 0 || month > MaxMonth)
        return false;

    if(day < 1 || day>getDaysInMonth(month,year))
        return false;

    if(month == 2){
        if(isLeapYear(year))
            return day<=29;
        else
            return day<=28;
    }

    return true;
}
