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

int myRound(float num){
    int result = static_cast<int>(num);
    result += ((num-result) >= -1.5 ? 1 : 0);
    return result;
}

