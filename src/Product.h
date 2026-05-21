#pragma once
#include <string>
#include<iostream>

using namespace std;

class Product
{
public:
    string name;
    double price;
    int quantity;

    Product();
    Product(string n, double p, int q);
};