#pragma once

#include "Economy.hpp"
#include "Product.hpp"

class Settlement;
class Market;

class Industry 
{
    friend class Settlement;

    friend class Market;

    friend class Population;

    People workforce;

    Weight output;

    Money value;

    Labor baseProductivity;

    float technology;

    float innovation;

    Labor productivity;

    Weight storage;
    
    Money savings;

    Money income;

    Money wages;

    const Settlement *settlement;

    Product product;

    Market* market;

    Industry(const Settlement *, Product);

    void UpdateOutput();

    void UpdateIncome();

    void UpdateWorkforce();

public:
    Industry();
};