#pragma once

#include "Container/Array.hpp"

#include "Economy.hpp"

class Industry;
class Market;
class Population;

class Settlement
{
    friend class Industry;

    friend class Market;

    friend class Population;

    container::Array <Industry> industries;
    
    container::Array <Market> markets;

    Population* population;

    void SetupEconomy();

    Settlement();

    Industry* GetIndustry(Product) const;

    Market* GetMarket(Product) const;

public:
    Settlement(People);

    void Update();
};