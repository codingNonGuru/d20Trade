#pragma once

#include <iostream>

class Product
{
public:
    explicit operator int();

    operator const char *();

    Product();

    Product(const char * name_);

private:
    int index;

    const char *name;
};