#pragma once

#include "Economy.hpp"

class Settlement;

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

    const Settlement& settlement;

    Industry(const Settlement&);

    void UpdateOutput();

    void UpdateIncome();

    void UpdateWorkforce();
};