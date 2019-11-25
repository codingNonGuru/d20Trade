#pragma once

typedef float Weight;

typedef int People;

typedef float Money;

typedef float Labor;

struct Product;

class Products
{
    friend struct Product;

public:
    static const Product FOOD; //Requires LAND as resource, TOOLS as materials
    //static const Product FIBER; //Requires LAND as resource, TOOLS as materials
    //static const Product LUMBER; //Requires WOODS as resource, TOOLS as materials
    //static const Product METAL; //Requires ORE as resource, TOOLS & LUMBER as materials
    //static const Product BRICKS; //Requires CLAY as resource, TOOLS & LUMBER as materials
    //static const Product TOOLS; //Requires TOOLS, METAL & LUMBER as materials
    //static const Product CLOTH; //Requires TOOLS & FIBER as materials
    //static const Product POTTERY; //Requires CLAY as resource, TOOLS as materials
    //static const Product FURNITURE; //Requires TOOLS & LUMBER as materials
    //static const Product BUILDING; //Requires TOOLS & LUMBER & BRICKS & METAL as materials

    static const Product* GetFirst();

    static const Product* GetLast();

    static int GetCount();

private:
    static int productIndex;

    static const int capacity = 64;

    static Product products[capacity];
};

