#include <iostream>

#include "Product.hpp"
#include "Economy.hpp"

Product::operator int() const {return index;}

Product::operator const char *() const {return name;}

Product::Product() {}

Product::Product(const char * name_, Weight dailyNeed_, Weight productivity_) : name(name_), dailyNeed(dailyNeed_), productivity(productivity_)
{
    index = Products::productIndex;

    Products::products[index] = *this;

    Products::productIndex++;
}