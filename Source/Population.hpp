#pragma once

#include "Economy.hpp"
#include "Types.hpp"

class Settlement;

class NeedHandler
{
    Weight effectiveNeeds[3];

protected:
    void SetNeed(const Product& product, Weight need);

public:
    Weight GetNeed(const Product& product) const;
};

class Population : NeedHandler
{
    friend class Settlement;

    friend class Market;

    friend class Industry;

    People count;

    People workforce;

    Money savings;

    Money income;

    Money expenses;

    Money averageIncome;

    Money averageExpenses;

    float affordability;

    float sustainability;

    const Settlement& settlement;

    Population(const Settlement&);

    void Setup();

    void UpdateSavings();

    void UpdateNeed();

    void UpdateOrder();

    void Print() const;

    bool HasFreeWorkers() const;
};