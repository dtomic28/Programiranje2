//
// Created by danijel on 4/1/2024.
//

#include "Bank.h"

Bank::Bank() = default;

Bank::~Bank()
{
    for (auto& account : accounts)
    {
        delete account;
    }
}

void Bank::addAccount(Account* account)
{
    accounts.push_back(account);
}

std::vector<Account*> Bank::getAccounts() const
{
    return accounts;
}

bool Bank::makeDepositOnAccount(double amount, unsigned int accountNumber)
{
    bool result = false;
    for (auto& account : accounts)
    {
        if (account->getNumber() == accountNumber)
        {
            result = account->makeDeposit(amount);
            break;
        }
    }
    return result;
}

bool Bank::makeWithdrawlOnAccount(double amount, unsigned int accountNumber)
{
    bool result = false;
    for (auto& account : accounts)
    {
        if (account->getNumber() == accountNumber)
        {
            if (dynamic_cast<SavingsAccount*>(account))
            {
                result = dynamic_cast<SavingsAccount*>(account)->makeWithdrawl(amount);
            }
            else
            {
                result = account->makeWithdrawl(amount);
            }
            break;
        }
    }
    return result;
}

void Bank::applyInterestRates()
{
    for (auto& account : accounts)
    {
        if (dynamic_cast<SavingsAccount*>(account))
        {
            auto acc = dynamic_cast<SavingsAccount*>(account);
            acc->makeDeposit(acc->getBalance() * acc->getIntrestRate());
        }
    }
}

std::string Bank::toString() const
{
    std::string result;

    for (auto& acc : accounts)
    {
        result += dynamic_cast<SavingsAccount*>(acc) ? dynamic_cast<SavingsAccount*>(acc)->toString() : acc->toString() + "\n";
    }

    return result;
}
