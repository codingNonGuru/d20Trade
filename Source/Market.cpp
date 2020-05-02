#include "FlumenCore/Utility/Utility.hpp"

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

void Market::UpdateTransaction()
{
    auto population = settlement->population;

    float variationFactor = 1.0f; //utility::GetRandom(0.95f, 1.05f);

    demand = (float)population->count * population->GetNeed(product) * variationFactor;

    offer = industry->output;

    order = demand > offer ? offer : demand;

    transaction = order * averagePrice;
}

void Market::UpdatePrice()
{
    float priceSignal = demand / offer;

    priceSignal = pow(priceSignal, 0.5f);

    price = industry->value * priceSignal;

    averagePrice = (averagePrice + price * 0.1f) / 1.1f;

    order *= settlement->population->affordability;

    transaction = order * averagePrice;
}