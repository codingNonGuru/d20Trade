#pragma once

#include "Economy.hpp"

class Settlement;

class Market
{
    friend class Settlement;

    friend class Industry;

    const Settlement& settlement;

    Weight demand;

    Weight offer;

    Weight order;

    Money price;

    Market(const Settlement&);

    void Update();
};