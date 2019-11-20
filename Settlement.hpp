#pragma once

#include "Economy.hpp"

class Industry;
class Market;
class Population;

class Settlement
{
    friend class Industry;

    friend class Market;

    friend class Population;

    Industry* industry;

    Market* market;

    Population* population;

public:
    Settlement();

    void Print();

    void Update();
};