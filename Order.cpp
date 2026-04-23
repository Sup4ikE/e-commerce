#include "Order.h"
#include <iostream>

string statusToString(Status s)
{
    switch (s)
    {
        case PENDING: return "Pending";
        case COMPLETED: return "Completed";
        case CANCELLED: return "Cancelled";
    }
    return "";
}

string paymentToString(PaymentMethod p)
{
    switch (p)
    {
        case CASH: return "Cash";
        case CARD: return "Card";
    }
    return "";
}

Order::Order(string d)
{
    date=d;
    status=PENDING;
    payment=CASH;
}

void Order::addProduct(Product p)
{
    for(auto& item:products)
    {
        if(item.name==p.name)
        {
            item.quantity+=p.quantity;
            return;
        }
    }

    products.push_back(p);
}

void Order::removeProduct(string name)
{
    products.erase(
        remove_if(products.begin(),
                  products.end(),
                  [&](Product p)
                  {
                      return p.name==name;
                  }),
        products.end()
    );
}

void Order::changeQuantity(string name,int qty)
{
    for(auto& p:products)
    {
        if(p.name==name)
        {
            p.quantity=qty;
            return;
        }
    }
}

void Order::setStatus(Status s)
{
    status=s;
}

void Order::setPayment(PaymentMethod p)
{
    payment=p;
}

void Order::setDate(string d)
{
    date=d;
}

double Order::getTotal()
{
    double total=0;

    for(auto p:products)
        total+=p.price*p.quantity;

    return total;
}

void Order::print()
{
    cout<<"\n==== ORDER ====\n";
    cout<<"Date: "<<date<<endl;
    cout<<"Status: "<<statusToString(status)<<endl;
    cout<<"Payment: "<<paymentToString(payment)<<endl;

    for(auto p:products)
    {
        cout<<p.name
            <<" x"<<p.quantity
            <<" = "<<p.price*p.quantity
            <<endl;
    }

    cout<<"TOTAL: "<<getTotal()<<endl;
}

void Order::saveToFile(string filename)
{
    ofstream file(filename);

    file<<date<<endl;
    file<<status<<endl;
    file<<payment<<endl;

    file<<products.size()<<endl;

    for(auto p:products)
    {
        file<<p.name<<" "
            <<p.price<<" "
            <<p.quantity<<endl;
    }

    file.close();
}

void Order::loadFromFile(string filename)
{
    ifstream file(filename);

    if(!file)
    {
        cout<<"File not found\n";
        return;
    }

    products.clear();

    int s,p,count;

    file>>date;
    file>>s;
    file>>p;

    status=(Status)s;
    payment=(PaymentMethod)p;

    file>>count;

    for(int i=0;i<count;i++)
    {
        string n;
        double price;
        int qty;

        file>>n>>price>>qty;

        products.push_back(
            Product(n,price,qty)
        );
    }

    file.close();
}