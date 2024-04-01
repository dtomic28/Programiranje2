//
// Created by danijel on 4/1/2024.
//

#ifndef PROGRAMIRANJE2_ACCOUNT_H
#define PROGRAMIRANJE2_ACCOUNT_H
#include "Person.h"

class Account {
private:
    Person* owner;
protected:
    unsigned int number;
    double balance;
public:
    Account(unsigned int number, double balance, Person* owner);
    virtual ~Account();

    Person *getOwner() const;

    unsigned int getNumber() const;

    double getBalance() const;

    bool makeDeposit(double amount);
    virtual bool makeWithdrawl(double amount);

    virtual std::string toString() const;
};


#endif //PROGRAMIRANJE2_ACCOUNT_H
