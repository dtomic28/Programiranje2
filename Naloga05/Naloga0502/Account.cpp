//
// Created by danijel on 4/1/2024.
//

#include "Account.h"

Account::~Account() = default;

Account::Account(unsigned int number, double balance, Person *owner) : number(number), balance(balance), owner(owner) {}

Person *Account::getOwner() const {
    return owner;
}

unsigned int Account::getNumber() const {
    return number;
}

double Account::getBalance() const {
    return balance;
}

bool Account::makeDeposit(double amount) {
    if (amount < 0)
        return false;

    balance += amount;
    return true;
}

bool Account::makeWithdrawl(double amount) {
    if (amount < 0)
        return false;

    if ((balance - amount) < 0)
        return false;

    balance -= amount;
    return true;
}

std::string Account::toString() const {
    return "Person: " + owner->toString() + "\n" +
           "Account number: " + std::to_string(number) + "\n"
           + "Balance: " + std::to_string(balance) + "\n";
}


