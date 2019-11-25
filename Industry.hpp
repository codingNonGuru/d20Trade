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

    float technology;

    float innovation;

    Weight productivity;

    Weight storage;
    
    Money savings;

    Money income;

    Money wages;

    Money averageIncome;

    Money averageWages;

    Money averageDues;

    float rentability;

    const Settlement *settlement;

    const Product *product;

    Market* market;

    Industry(const Settlement *, const Product *);

    void UpdateOutput();

    void UpdateIncome();

    void UpdateWorkforce();

    void UpdateProductivity();

public:
    Industry();
};