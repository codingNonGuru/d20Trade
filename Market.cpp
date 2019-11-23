#include "Utility.hpp"

#include "Market.hpp"
#include "Settlement.hpp"
#include "Industry.hpp"
#include "Population.hpp"

Market::Market() {}

Market::Market(const Settlement *settlement_, Product product_) : settlement(settlement_), product(product_)
{
    std::cout<<product<<" market was created!\n";

    industry = settlement->GetIndustry(product);

    averagePrice = industry->value;
}

void Market::Update()
{
    auto population = settlement->population;

    float variationFactor = utility::GetRandom(0.99f, 1.01f);

    demand = (float)population->count * population->effectiveNeed * variationFactor;

    offer = industry->output;

    order = demand > offer ? offer : demand;

    float priceSignal = demand / offer;

    priceSignal = pow(priceSignal, 0.3f);

    price = industry->value * priceSignal;

    averagePrice = (averagePrice + price * 0.1f) / 1.1f;

    std::cout<<"The price of "<<product<<" is "<<averagePrice<<" coins\n";
}