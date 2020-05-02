#include <math.h>

#include "Population.hpp"
#include "Settlement.hpp"
#include "Industry.hpp"
#include "Market.hpp"

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

    workforce = 0;
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

    for(int i = 0; i < savings / 5.5f; ++i)
    {
        //std::cout<<"I";
    }
    //std::cout<<"\n";
}

void Population::UpdateNeed()
{
    sustainability = averageIncome / averageExpenses;
    if(sustainability > 1.0f)
    {
        sustainability = 1.0f;
    }
    sustainability = pow(sustainability, 2.0f);

    auto deficit = averageExpenses - averageIncome;
    if(deficit > 0.001f)
    {
        auto deficitFactor = savings / deficit;
        if(deficitFactor > 0.0f && deficitFactor < 20.0f)
        {
            deficitFactor /= 20.0f;
            deficitFactor = pow(deficitFactor, 2.0f);

            sustainability *= deficitFactor;
        }
    }
    
    /*if(std::isnan(-affordability))
    {
        abort();
    }*/

    for(auto product = Products::GetFirst(); product != Products::GetLast(); ++product)
    {
        auto need = product->GetDailyNeed() * sustainability;

        SetNeed(*product, need);
    }
}

void Population::UpdateOrder()
{
    Money aggregateTransaction = 0.0f;

    auto& markets = settlement.markets;
    for(auto market = markets.GetStart(); market != markets.GetEnd(); ++market)
    {
        aggregateTransaction += market->transaction;
    }

    affordability = savings / aggregateTransaction;
    if(affordability > 1.0f)
    {
        affordability = 1.0f;
    }
    if(affordability < 0.0f)
    {
        affordability = 0.0f;
    }
}

bool Population::HasFreeWorkers() const
{
    return workforce < count;
}

void Population::Print() const
{
    std::cout<<"Need factor is "<<affordability<<"\n";

    std::cout<<"The population saved "<<savings<<" coins, earned "<<income<<" coins and spent "<<expenses<<" coins.\n";
}