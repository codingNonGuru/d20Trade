#pragma once

#include "Economy.hpp"

class Product
{
public:
    explicit operator int();

    operator const char *();

    Product();

    Product(const char *, Weight);

    Weight GetDailyNeed() const {return dailyNeed;}

private:
    int index;

    const char *name;

    Weight dailyNeed;
};