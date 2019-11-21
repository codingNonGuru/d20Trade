#include "Utility.hpp"

#include "Market.hpp"
#include "Settlement.hpp"
#include "Industry.hpp"
#include "Population.hpp"

Market::Market() {}

Market::Market(const Settlement *settlement_, Product product_) : settlement(settlement_), product(product_)
{
    std::cout<<product<<" market was created!\n";
    //industry = settlement->industries.Get(product);
    industry = settlement->GetIndustry(product);
}

void Market::Update()
{
    auto population = settlement->population;

    float variationFactor = utility::GetRandom(0.9f, 1.1f);

    demand = (float)population->count * population->need * variationFactor;

    offer = industry->output;

    order = demand > offer ? offer : demand;

    float priceSignal = demand / offer;

    priceSignal = sqrt(priceSignal);

    price = industry->value * priceSignal;
}