#include <iostream>

#include "Product.hpp"
#include "Economy.hpp"

Product::operator int() {return index;}

Product::operator const char *() {return name;}

Product::Product() {}

Product::Product(const char * name_, Weight dailyNeed_) : name(name_), dailyNeed(dailyNeed_)
{
    index = Products::productIndex;

    Products::products[index] = *this;

    Products::productIndex++;
}