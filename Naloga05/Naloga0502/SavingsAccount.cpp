//
// Created by danijel on 4/1/2024.
//

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(unsigned int number, double balance, Person *owner, double intrestRate) : Account(number,
                                                                                                                 balance,
                                                                                                                 owner),
                                                                                                         intrestRate(
                                                                                                                 intrestRate) {
    lastWithdrawlDate = Date();
}

double SavingsAccount::getIntrestRate() const {
    return intrestRate;
}

void SavingsAccount::setIntrestRate(double intrestRate) {
    SavingsAccount::intrestRate = intrestRate;
}

bool SavingsAccount::makeWithdrawl(double amount) {
    unsigned int differenceDays= abs(lastWithdrawlDate.getDaysSinceEpoch() - Date::getCurrentDate().getDaysSinceEpoch());
    if(differenceDays>=90){
        lastWithdrawlDate = Date::getCurrentDate();
        return Account::makeWithdrawl(amount);
    }
    else{
        return false;
    }
}

std::string SavingsAccount::toString() const {
    return Account::toString() + "Interest rate: " + std::to_string(intrestRate) +"\n" + lastWithdrawlDate.toString() + "\n\n";
}
