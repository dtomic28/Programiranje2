//
// Created by Danijel Tomić on 7. 03. 24.
//

#ifndef PROGRAMIRANJE2_EXPENSE_H
#define PROGRAMIRANJE2_EXPENSE_H

#include <string>

class Expense
{
private:
    float value;
    unsigned int day, month, year;
    std::string description;

public:
    Expense(float value, unsigned int day, unsigned int month, unsigned int year, std::string& description);

    Expense();

    Expense(const Expense& expense);

    float getValue();

    unsigned int getDay();

    unsigned int getMonth();

    unsigned int getYear();

    std::string getDescription();

    void setValue(float value);

    std::string toString(bool rounded = false);
};

int myRound(float num);
bool isHigherDate(Expense expense, unsigned int day, unsigned int month, unsigned int year);

#endif  // PROGRAMIRANJE2_EXPENSE_H
