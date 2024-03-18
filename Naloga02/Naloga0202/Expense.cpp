//
// Created by Danijel Tomić on 7. 03. 24.
//

#include "Expense.h"
#include <string>

Expense::Expense(float value, unsigned int day, unsigned int month, unsigned int year, std::string &description) {
    this->value = value;
    this->day = day;
    this->month = month;
    this->year = year;
    this->description = description;
}

float Expense::getValue() {
    return this->value;
}

unsigned int Expense::getDay() {
    return this->day;
}

unsigned int Expense::getMonth() {
    return this->month;
}

unsigned int Expense::getYear() {
    return this->year;
}

std::string Expense::getDescription() {
    return this->description;
}

void Expense::setValue(float value) {
    this->value = value;
}

std::string Expense::toString(bool rounded) {
    if(rounded)
        return std::to_string(myRound(this->value)) + " (" + std::to_string(this->day) + "." +
               std::to_string(this->month) + "." + std::to_string(this->year) + ") - " + this->description;
    else
        return std::to_string(this->value) + " (" + std::to_string(this->day) + "." +
               std::to_string(this->month) + "." + std::to_string(this->year) + ") - "+ this->description;
}

Expense::Expense() {
    this->value = 0;
    this->description = "Description";
    this->day = 1;
    this->month = 1;
    this->year = 2024;
}

Expense::Expense(const Expense &expense) {
    this->value = expense.value;
    this->month = expense.month;
    this->description = expense.description;
    this->day = expense.day;
    this->year = expense.year;
}


int myRound(float num){
    int result = static_cast<int>(num);
    result += ((num-result) >= -1.5 ? 1 : 0);
    return result;
}

bool isHigherDate(Expense expense, unsigned int day, unsigned int month, unsigned int year) {
    if(expense.getYear()>year)
        return true;
    if(year == expense.getYear() && expense.getMonth() > month)
        return true;
    if(expense.getYear() == year && expense.getMonth() == month && expense.getDay() > day)
        return true;

    return false;
}

