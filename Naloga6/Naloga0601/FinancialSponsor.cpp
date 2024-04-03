//
// Created by Danijel Tomić on 3. 04. 24.
//

#include "FinancialSponsor.h"
FinancialSponsor::FinancialSponsor(const std::string& name,
                                   unsigned int yearsOfSponsorship,
                                   float moneyDonated,
                                   const std::string& bankAccount)
    : Sponsor(name, yearsOfSponsorship)
    , bankAccount(bankAccount)
{
    if (moneyDonated >= 0)
    {
        this->moneyDonated = moneyDonated;
    }
}
float FinancialSponsor::calculateScore() const
{
    return ((0.7f * moneyDonated) + (0.3f * yearsOfSponsorship)) / (moneyDonated + yearsOfSponsorship);
}
std::string FinancialSponsor::toString() const
{
    return Sponsor::toString() + "Money donated: " + std::to_string(moneyDonated) + "\n" + "Bank account: " + bankAccount + "\n";
}
FinancialSponsor::FinancialSponsor(const FinancialSponsor& financialSponsor) = default;

FinancialSponsor::FinancialSponsor()
    : Sponsor("Financial sponsor", 0)
    , moneyDonated(0)
{
}
