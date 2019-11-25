#include <math.h>

#include "Population.hpp"
#include "Settlement.hpp"
#include "Industry.hpp"

void NeedHandler::SetNeed(const Product& product, Weight need) 
{
    effectiveNeeds[(int)product] = need;
}

Weight NeedHandler::GetNeed(const Product& product) const 
{
    return effectiveNeeds[(int)product];
}

Population::Population(const Settlement& parent) : settlement(parent)
{
    count = 100;
}

void Population::Setup()
{
    savings = 1000.0f;

    income = 0.0f;

    auto& industries = settlement.industries;
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        income += industry->wages;
    }

    averageIncome = income;

    expenses = income;

    averageExpenses = expenses;
}

void Population::UpdateSavings()
{
    income = 0.0f;

    expenses = 0.0f;

    auto& industries = settlement.industries;
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        income += industry->wages;

        expenses += industry->income;
    }

    savings += income;

    savings -= expenses;

    averageIncome = (averageIncome + income * 0.1f) / 1.1f;

    averageExpenses = (averageExpenses + expenses * 0.1f) / 1.1f;
}

void Population::UpdateNeed()
{
    affordability = averageIncome / averageExpenses;
    if(affordability > 1.0f)
    {
        affordability = 1.0f;
    }
    affordability = pow(affordability, 2.0f);

    if(averageExpenses > averageIncome)
    {
        auto sustainability = savings / (averageExpenses - averageIncome);
        if(sustainability < 10.0f)
        {
            sustainability /= 10.0f;

            affordability *= sustainability;
        }
    }

    for(auto product = Products::GetFirst(); product != Products::GetLast(); ++product)
    {
        auto need = product->GetDailyNeed() * affordability;

        SetNeed(*product, need);
    }
}

void Population::Print() const
{
    std::cout<<"Need factor is "<<affordability<<"\n";

    std::cout<<"The population saved "<<savings<<" coins, earned "<<income<<" coins and spent "<<expenses<<" coins.\n";
}