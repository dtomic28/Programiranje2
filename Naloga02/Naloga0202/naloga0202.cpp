//
// Created by Danijel Tomić on 27. 02. 24.
//

#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include "Expense.h"
#include <vector>

using namespace std;

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1 ... GENERATE EXPENSES" << endl;
    cout << "2 ... PRINT EXPENSES" << endl;
    cout << "3 ... PRINT EXPENSES (ROUNDED)" << endl;
    cout << "4 ... PRINT AVG. EXPENSE COST" << endl;
    cout << "5 ... PRINT THE CHEAPEST EXPENSE" << endl;
    cout << "6 ... PRINT HOW MANY TIMES THE EXPENSE WAS OVER 100" << endl;
    cout << "7 ... SORT ARRAY" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void sort(vector<Expense> &array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = i; j < array.size(); j++) {
            if (array[i].getValue() < array[j].getValue()) {
                swap(array[i], array[j]);
            }
        }
    }
}

float generateRandomFloatInRange(float min, float max) {
    return min + static_cast<float>(rand()) / (RAND_MAX / (max - min));
}

void fillArray(vector<Expense> &array, const unsigned int size) {
    string description = "Nakup";
    for (unsigned int i = 0; i < size; i++) {
        array.emplace_back(generateRandomFloatInRange(0.50, 150.00), int(generateRandomFloatInRange(1, 31)),
                           int(generateRandomFloatInRange(1, 12)), 2024, description);
    }
}

void printArray(vector<Expense> array) {
    for (auto &expense: array) {
        cout << expense.toString() << endl;
    }
}

void roundAndPrintArray(vector<Expense> array) {
    for (auto &expense: array) {
        cout << expense.toString(true) << endl;
    }
}

float calculateAvgValueOfExpenses(vector<Expense> array) {
    float count = 0;
    for (auto &expense: array) {
        count += expense.getValue();
    }
    return count / array.size();
}

int getIndexOfMinValue(vector<Expense> array) {
    int result = 0;
    for (int i = 1; i < array.size(); i++) {
        if (array[i].getValue() < array[result].getValue())
            result = i;
    }
    return result;
}

int howManyOverAHunderd(vector<Expense> array) {
    int result = 0;
    for (auto &expense: array) {
        if (expense.getValue() > 100)
            result++;
    }
    return result;
}

int main() {
    const unsigned int numOfExpenses = 20;
    vector<Expense> expenses;

    srand(time(nullptr));

    bool running = true;
    int selection;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                fillArray(expenses, numOfExpenses);
                break;
            case 2:
                printArray(expenses);
                break;
            case 3:
                roundAndPrintArray(expenses);
                break;
            case 4:
                cout << "Avrage cost of expense: " << calculateAvgValueOfExpenses(expenses) << endl;
                break;
            case 5:
                cout << "Cheapest expense: " << expenses[getIndexOfMinValue(expenses)].getValue() << endl;
                break;
            case 6:
                cout << "Expenses over 100: " << howManyOverAHunderd(expenses) << endl;
                break;
            case 7:
                sort(expenses);
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    expenses.clear();

    return 0;
}
