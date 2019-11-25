#include <iostream>

#include "Utility.hpp"

#include "Industry.hpp"
#include "Settlement.hpp"
#include "Market.hpp"
#include "Population.hpp"

Industry::Industry() {}

Industry::Industry(const Settlement *settlement_, Product product_) : settlement(settlement_), product(product_)
{
    baseProductivity = 0.3f;

    technology = 1.5f;
    
    innovation = 1.0f;

    productivity = baseProductivity * innovation;

    value = 1.0f / productivity;

    workforce = settlement->population->count / 10;

    storage = 0.0f;

    savings = 0.0f;

    market = settlement->GetMarket(product);

    wages = (float)workforce * productivity;

    averageWages = wages;

    averageIncome = wages;
}

void Industry::UpdateOutput()
{
    float variationFactor = utility::GetRandom(0.99f, 1.01f);

    output = (float)workforce * productivity * variationFactor;
}

void Industry::UpdateIncome()
{
    income = market->order * market->averagePrice;

    wages = market->order * value;
    if(wages > income)
    {
        auto difference = wages - income;
        if(difference > savings)
        {
            difference = savings;
        }
        wages = income + difference;
    }

    averageWages = (averageWages + wages * 0.1f) / 1.1f;

    averageIncome = (averageIncome + income * 0.1f) / 1.1f;

    savings += income - wages;

    std::cout<<product<<" producers have saved "<<savings<<" coins\n";
}

void Industry::UpdateWorkforce()
{
    auto rentability = (averageIncome - averageWages) / averageIncome;

    if(rentability > 0.0f)
    {
        auto increaseChance = pow(rentability, 0.7f);
        if(utility::RollDice(increaseChance) == true)
        {
            workforce++;
        }
    }
    else
    {
        auto decreaseChance = pow(-rentability, 1.3f);
        if(utility::RollDice(decreaseChance) == true)
        {
            workforce--;
        }
    }

    //std::cout<<product<<" rentability is "<<rentability<<"\n";

    std::cout<<"The "<<product<<" industry has "<<workforce<<" workers\n";
}

void Industry::UpdateProductivity()
{
    auto innovationGap = (technology - innovation) / technology;

    innovation += 0.0035f;

    productivity = baseProductivity * innovation;

    value = 1.0f / productivity;

    innovation = pow(innovation, 0.995f);
}