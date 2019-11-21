#pragma once

struct Product
{
    operator int();

    operator const char *();

    Product();

    Product(const char * name_);

private:
    int index;

    const char *name;
};