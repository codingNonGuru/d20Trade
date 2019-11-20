#include <iostream>

#include "Utility.hpp"

#include "Industry.hpp"
#include "Settlement.hpp"
#include "Market.hpp"
#include "Population.hpp"

Industry::Industry(const Settlement& parent) : settlement(parent)
{
    baseProductivity = 0.3f;

    technology = 1.5f;
    
    innovation = 1.0f;

    productivity = baseProductivity * innovation;

    value = 1.0f / productivity;

    workforce = settlement.population->count / 10;

    storage = 0.0f;

    //rawMaterials = 

    savings = 0.0f;
}

void Industry::UpdateOutput()
{
    float variationFactor = utility::GetRandom(0.9f, 1.1f);

    output = (float)workforce * baseProductivity * variationFactor;
}

void Industry::UpdateIncome()
{
    income = settlement.market->order * settlement.market->price;

    wages = settlement.market->order * value;

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