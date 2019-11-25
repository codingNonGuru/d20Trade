#include "Economy.hpp"
#include "Product.hpp"

int Products::productIndex = 0;

//const Product Products::TOOLS = Product("Tools", 0.1f);
const Product Products::FOOD = Product("Food", 0.3f);
const Product Products::FIBER = Product("Fiber", 0.1f);
const Product Products::LUMBER = Product("Lumber", 0.1f);
/*const Product Products::BRICKS = Product("Bricks", 0.1f);
const Product Products::WINE = Product("Lumber");
const Product Products::METAL = Product("Lumber");
const Product Products::CLOTH = Product("Cloth");
const Product Products::FURNITURE = Product("Furniture", 0.3f);
const Product Products::POTTERY = Product("Pottery", 0.3f);
const Product Products::GLASS = Product("Glass", 0.3f);
const Product Products::PAPER = Product("Paper", 0.3f);
const Product Products::BUILDING = Product("Building", 0.3f);
const Product Products::CONTAINER = Product("Container", 0.3f);
const Product Products::CART = Product("Cart", 0.3f);
const Product Products::SHIP = Product("Ship", 0.3f);
const Product Products::WEAPON = Product("Weapon", 0.3f);
const Product Products::MACHINERY = Product("Machinery", 0.3f);
const Product Products::DYES = Product("Dyes", 0.3f);
const Product Products::SOAP = Product("Soap", 0.3f);
const Product Products::CANDLES = Product("Candles", 0.3f);
const Product Products::TAR = Product("Tar", 0.3f);
const Product Products::MEDICINE = Product("Medicine", 0.3f);
const Product Products::ROPE = Product("Rope", 0.3f);
const Product Products::LEATHER = Product("Leather", 0.3f);
const Product Products::SHOES = Product("Shoes", 0.3f);
const Product Products::METALWARE = Product("Metalware", 0.3f);
const Product Products::JEWELRY = Product("Jewelry", 0.3f);
const Product Products::TAPESTRY = Product("Tapestry", 0.3f);
const Product Products::CLOTHING = Product("Clothing", 0.3f);*/

//const Resource Resources::LAND = Resource("Land", 0.1f);
//const Resource Resources::CLAY = Resource("Clay", 0.1f);
//const Resource Resources::WOODS = Resource("Woods", 0.1f);
//const Resource Resources::ORE = Resource("Ore", 0.1f);

Product Products::products[Products::capacity];

const Product* Products::GetFirst() {return products;}

const Product* Products::GetLast() {return products + productIndex;}

int Products::GetCount() {return productIndex;}