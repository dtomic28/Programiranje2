//
// Created by danijel on 4/1/2024.
//

#ifndef PROGRAMIRANJE2_BANK_H
#define PROGRAMIRANJE2_BANK_H
#include "Account.h"
#include "SavingsAccount.h"
#include <vector>

class Bank
{
private:
    std::vector<Account*> accounts;

public:
    Bank();
    ~Bank();

    void addAccount(Account* account);
    std::vector<Account*> getAccounts() const;

    bool makeDepositOnAccount(double amount, unsigned int accountNumber);
    bool makeWithdrawlOnAccount(double amount, unsigned int accountNumber);
    void applyInterestRates();

    std::string toString() const;
};

#endif  // PROGRAMIRANJE2_BANK_H
