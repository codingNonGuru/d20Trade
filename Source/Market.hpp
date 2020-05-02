#pragma once

#include "Economy.hpp"
#include "Product.hpp"

class Settlement;
class Industry;

class Market
{
    friend class Settlement;

    friend class Industry;

    friend class Population;

    const Settlement *settlement;

    Weight demand;

    Weight offer;

    Weight order;

    Money transaction;

    Money price;

    Money averagePrice;

    Product product;

    Industry* industry;

    Market(const Settlement *, Product);

    void UpdateTransaction();

    void UpdatePrice();

public:
    Market();
};