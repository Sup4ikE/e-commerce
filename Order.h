#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Product.h"

using namespace std;

enum Status
{
    PENDING,
    COMPLETED,
    CANCELLED
};

enum PaymentMethod
{
    CASH,
    CARD
};

string statusToString(Status s);
string paymentToString(PaymentMethod p);

class Order
{
private:
    vector<Product> products;
    string date;
    Status status;
    PaymentMethod payment;

public:
    Order(string d = "01-01-2026");

    void addProduct(Product p);
    void removeProduct(string name);
    void changeQuantity(string name,int qty);

    void setStatus(Status s);
    void setPayment(PaymentMethod p);
    void setDate(string d);

    double getTotal();
    void print();

    void saveToFile(string filename);
    void loadFromFile(string filename);
};