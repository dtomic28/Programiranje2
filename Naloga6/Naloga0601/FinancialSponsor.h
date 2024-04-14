//
// Created by Danijel Tomić on 3. 04. 24.
//

#ifndef PROGRAMIRANJE2_FINANCIALSPONSOR_H
#define PROGRAMIRANJE2_FINANCIALSPONSOR_H
#include "Sponsor.h"

class FinancialSponsor : public Sponsor
{
private:
    float moneyDonated;
    std::string bankAccount;

public:
    FinancialSponsor(const std::string& name, unsigned int yearsOfSponsorship, float moneyDonated, const std::string& bankAccount);
    FinancialSponsor();
    FinancialSponsor(const FinancialSponsor& financialSponsor);

    ~FinancialSponsor();

    std::string getPromoText() const override;
    float calculateScore() const override;
    std::string toString() const override;
};

#endif  // PROGRAMIRANJE2_FINANCIALSPONSOR_H
