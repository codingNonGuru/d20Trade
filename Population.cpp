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

    spending = income;

    averageSpending = spending;

    /*auto& markets = settlement.markets;
    for(auto market = markets.GetStart(); market != markets.GetEnd(); ++market)
    {
        spending += 
    }*/
}

void Population::UpdateSavings()
{
    income = 0.0f;

    spending = 0.0f;

    auto& industries = settlement.industries;
    for(auto industry = industries.GetStart(); industry != industries.GetEnd(); ++industry)
    {
        income += industry->wages;

        spending += industry->income;
    }

    savings += income;

    savings -= spending;

    averageIncome = (averageIncome + income * 0.1f) / 1.1f;

    averageSpending = (averageSpending + spending * 0.1f) / 1.1f;

    std::cout<<"The population saved "<<savings<<" coins, earned "<<income<<" coins and spent "<<spending<<" coins.\n";
}

void Population::UpdateNeed()
{
    auto subsistenceLevel = averageIncome / averageSpending;
    if(subsistenceLevel > 1.0f)
    {
        subsistenceLevel = 1.0f;
    }
    subsistenceLevel = pow(subsistenceLevel, 2.0f);

    effectiveNeed = baseNeed * subsistenceLevel;
    std::cout<<"Need factor is "<<subsistenceLevel<<"\n";
}