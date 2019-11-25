#include <iostream>

#include "Utility.hpp"

#include "Industry.hpp"
#include "Settlement.hpp"
#include "Market.hpp"
#include "Population.hpp"

Industry::Industry() {}

Industry::Industry(const Settlement *settlement_, const Product *product_) : settlement(settlement_), product(product_)
{
    technology = 1.5f;
    
    innovation = 1.0f;

    productivity = product->GetProductivity() * innovation;

    value = 1.0f / productivity;

    workforce = settlement->population->count / 5;
    //workforce *= 4;

    storage = 0.0f;

    savings = 0.0f;

    market = settlement->GetMarket(*product);

    wages = (float)workforce * value;

    averageDues = wages;

    averageIncome = wages;
}

void Industry::UpdateOutput()
{
    float variationFactor = 1.0f;//utility::GetRandom(0.95f, 1.05f);

    output = (float)workforce * productivity * variationFactor;
}

void Industry::UpdateIncome()
{
    income = market->order * market->averagePrice;

    auto dues = market->order * value;
    wages = dues;
    if(wages > income)
    {
        auto difference = wages - income;
        if(difference > savings)
        {
            difference = savings;
        }
        wages = income + difference;
    }

    averageDues = (averageDues + dues * 0.1f) / 1.1f;

    averageIncome = (averageIncome + income * 0.1f) / 1.1f;

    savings += income - wages;

    //std::cout<<*product<<" producers have saved "<<savings<<" coins\n";
}

void Industry::UpdateWorkforce()
{
    rentability = (averageIncome - averageDues) / averageIncome;

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
        auto decreaseChance = pow(-rentability, 1.0f);
        if(utility::RollDice(decreaseChance) == true)
        {
            workforce--;
        }
    }
}

void Industry::UpdateProductivity()
{
    auto innovationGap = (technology - innovation) / technology;

    //innovation += 0.0035f;

    productivity = product->GetProductivity() * innovation;

    value = 1.0f / productivity;

    //innovation = pow(innovation, 0.995f);
}