#include "Product.hpp"
#include "Economy.hpp"

Product::operator int() {return index;}

Product::operator const char *() {return name;}

Product::Product() {}

Product::Product(const char * name_) : name(name_)
{
    index = Products::productIndex;

    Products::products[index] = *this;

    Products::productIndex++;
}