#include "Utility.hpp"

#include "Market.hpp"
#include "Settlement.hpp"
#include "Industry.hpp"
#include "Population.hpp"

Market::Market(const Settlement& parent) : settlement(parent)
{
    
}

void Market::Update()
{
    auto population = settlement.population;

    float variationFactor = utility::GetRandom(0.9f, 1.1f);

    demand = (float)population->count * population->need * variationFactor;

    offer = settlement.industry->output;

    order = demand > offer ? offer : demand;

    float priceSignal = demand / offer;

    priceSignal = sqrt(priceSignal);

    price = settlement.industry->value * priceSignal;
}