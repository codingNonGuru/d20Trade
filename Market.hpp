#pragma once

#include "Economy.hpp"
#include "Product.hpp"

class Settlement;
class Industry;

class Market
{
    friend class Settlement;

    friend class Industry;

    const Settlement *settlement;

    Weight demand;

    Weight offer;

    Weight order;

    Money price;

    Product product;

    Industry* industry;

    Market(const Settlement *, Product);

    void Update();

public:
    Market();
};