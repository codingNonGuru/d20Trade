#pragma once

#include "Economy.hpp"

class Settlement;

class Population
{
    friend class Settlement;

    friend class Market;

    friend class Industry;

    Weight need;

    People count;

    Money savings;

    const Settlement& settlement;

    Population(const Settlement&);

    void UpdateSavings();
};