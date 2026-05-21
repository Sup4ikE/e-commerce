#include "../src/Product.h"

Product::Product()
{
    name = "";
    price = 0;
    quantity = 0;
}

Product::Product(string n, double p, int q)
{
    name = n;
    price = p;
    quantity = q;
}