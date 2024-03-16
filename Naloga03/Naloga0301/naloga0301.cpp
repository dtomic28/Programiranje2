//
// Created by danijel on 3/16/2024.
//
#include "date.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<Date> dates;

    dates.emplace_back(28,10,2004);
    cout << dates[0].toString() << endl;

    dates.emplace_back(123,123,123);
    cout << dates[1].toString() << endl;

    dates.emplace_back(29,2, 2023);
    cout << dates[2].toString() << endl;

    dates.emplace_back(29,2, 2024);
    cout << dates[3].toString() << endl;

    cout << Date::isLeapYear(2024) << endl;

    cout << Date::getDaysInMonth(2, 2024) << endl;

    cout << Date::isDateValid(123,123,123) << endl;

    cout << Date::getDaysInMonth(15, 2024) << endl;

    return 0;
}
