//
// Created by danijel on 3/16/2024.
//

#include "Date.h"
#include "../Naloga0302/TextUtility.h"
#include <vector>
#include <iostream>

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    if (isDateValid(day, month, year)) {
        this->day = day;
        this->month = month;
        this->year = year;
    } else {
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }
}

Date::Date() : day(1), month(1), year(1970) {
}

Date::Date(const Date &date) = default;

std::string Date::toString() const {
    return std::to_string(this->day) + "." + std::to_string(this->month) + "." + std::to_string(this->year);
}

bool Date::isLeapYear(unsigned int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

unsigned int Date::getDaysInMonth(unsigned int month, unsigned int year) {
    if (month < 1 || month > MaxMonth)
        return 0;

    if (month == 2 && isLeapYear(year))
        return MaxDayByMonth[1]+1;


    return MaxDayByMonth[month - 1];
}

bool Date::isDateValid(unsigned int day, unsigned int month, unsigned int year) {
    if (year < 1970)
        return false;

    if (month <= 0 || month > MaxMonth)
        return false;

    if (day < 1 || day > getDaysInMonth(month, year))
        return false;

    if (month == 2) {
        if (isLeapYear(year))
            return day <= MaxDayByMonth[1]+1;
        else
            return day <= MaxDayByMonth[1];
    }

    return true;
}

Date Date::parse(const std::string& dateStr) {
    std::vector<int> nums =  TextUtility::extractIntNumbers(dateStr);
    Date result;
    if(nums.size() == 3 && Date::isDateValid(nums[0], nums[1], nums[2])){
        result.setDay(nums[0]);
        result.setMonth(nums[1]);
        result.setYear(nums[2]);
    }
    return result;
}

void Date::setDay(unsigned int day) {
    Date::day = day;
}

void Date::setMonth(unsigned int month) {
    Date::month = month;
}

void Date::setYear(unsigned int year) {
    Date::year = year;
}
