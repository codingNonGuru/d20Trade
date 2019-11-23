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

    wages = (float)workforce * baseProductivity;
}

void Industry::UpdateOutput()
{
    float variationFactor = utility::GetRandom(0.99f, 1.01f);

    output = (float)workforce * baseProductivity * variationFactor;
}

void Industry::UpdateIncome()
{
    income = market->order * market->averagePrice;

    wages = market->order * value;

    savings += income - wages;

    std::cout<<product<<" producers have saved "<<savings<<" coins\n";
}

void Industry::UpdateWorkforce()
{
    auto rentability = (income - wages) / income;

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

    std::cout<<product<<" rentability is "<<rentability<<"\n";

    auto innovationGap = (technology - innovation) / technology;

    innovation = pow(innovation, 0.99f);

    std::cout<<"The "<<product<<" industry has "<<workforce<<" workers\n";
}