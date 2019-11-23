#pragma once

#include "Economy.hpp"

class Settlement;

class Population
{
    friend class Settlement;

    friend class Market;

    friend class Industry;

    const Weight baseNeed = 0.1f;

    Weight effectiveNeed;

    People count;

    Money savings;

    Money income;

    Money spending;

    Money averageIncome;

    Money averageSpending;

    const Settlement& settlement;

    Population(const Settlement&);

    void Setup();

    void UpdateSavings();

    void UpdateNeed();
};