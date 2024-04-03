//
// Created by danijel on 4/1/2024.
//

#ifndef PROGRAMIRANJE2_SAVINGSACCOUNT_H
#define PROGRAMIRANJE2_SAVINGSACCOUNT_H
#include "Account.h"
#include "Date.h"

class SavingsAccount : public Account
{
private:
    double intrestRate;
    Date lastWithdrawlDate;

public:
    SavingsAccount(unsigned int number, double balance, Person* owner, double intrestRate);

    double getIntrestRate() const;

    void setIntrestRate(double intrestRate);

    bool makeWithdrawl(double amount) override;

    std::string toString() const override;
};

#endif  // PROGRAMIRANJE2_SAVINGSACCOUNT_H
