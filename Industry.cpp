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

    market = settlement->markets.Get(product);
}

void Industry::UpdateOutput()
{
    float variationFactor = utility::GetRandom(0.9f, 1.1f);

    output = (float)workforce * baseProductivity * variationFactor;
}

void Industry::UpdateIncome()
{
    income = market->order * market->price;

    wages = market->order * value;

    savings += income - wages;
}

void Industry::UpdateWorkforce()
{
    auto rentability = (income - wages) / income;

    if(utility::RollDice(rentability) == true)
    {
        workforce++;
        std::cout<<"New worker was hired!\n";
    }

    auto innovationGap = (technology - innovation) / technology;

    innovation = pow(innovation, 0.99f);
}