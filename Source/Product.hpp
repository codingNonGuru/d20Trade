#pragma once

#include "Economy.hpp"
#include "Types.hpp"

class Product
{
public:
    explicit operator int() const;

    operator const char *() const;

    Product();

    Product(const char *, Weight, Weight);

    Weight GetDailyNeed() const {return dailyNeed;}

    Weight GetProductivity() const {return productivity;}

private:
    int index;

    const char *name;

    Weight dailyNeed;

    Weight productivity;
};