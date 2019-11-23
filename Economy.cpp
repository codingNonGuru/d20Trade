#include "Economy.hpp"
#include "Product.hpp"

int Products::productIndex = 0;

const Product Products::FOOD = Product("Food");
/*const Product Products::FIBER = Product("Fiber");
const Product Products::CLAY = Product("Clay");
const Product Products::LUMBER = Product("Lumber");
const Product Products::TOOLS = Product("Tools");
const Product Products::CLOTH = Product("Cloth");*/

Product Products::products[Products::capacity];

const Product* Products::GetFirst() {return products;}

const Product* Products::GetLast() {return products + productIndex;}

int Products::GetCount() {return productIndex;}