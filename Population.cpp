#include <math.h>

#include "Population.hpp"
#include "Settlement.hpp"
#include "Industry.hpp"

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

    std::cout<<"The population saved "<<savings<<" coins, earned "<<income<<" coins and spent "<<expenses<<" coins.\n";
}

void Population::UpdateNeed()
{
    auto affordability = averageIncome / averageExpenses;
    if(affordability > 1.0f)
    {
        affordability = 1.0f;
    }
    affordability = pow(affordability, 2.0f);

    effectiveNeed = baseNeed * affordability;

    auto sustainability = savings / averageExpenses;
    if(sustainability < 3.0f)
    {
        sustainability /= 3.0f;

        effectiveNeed *= sustainability;
    }

    std::cout<<"Need factor is "<<affordability<<"\n";
}