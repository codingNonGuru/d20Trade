#pragma once

typedef float Weight;

typedef float People;

typedef float Money;

typedef float Labor;

struct Product;

class Products
{
    friend struct Product;

public:
    static const Product FOOD;
    static const Product FIBER;
    static const Product CLAY;
    static const Product LUMBER;
    static const Product TOOLS;

    static const Product* GetFirst();

    static const Product* GetLast();

    static int GetCount();

private:
    static int productIndex;

    static const int capacity = 16;

    static Product products[capacity];
};

