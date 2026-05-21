#include <iostream>
#include <vector>
#include "../src/Order.h"

using namespace std;

int main()
{
    vector<string> names=
    {
        "Milk",
        "Bread",
        "Cheese",
        "Juice"
    };

    vector<double> prices=
    {
        42.5,
        28.0,
        135.0,
        18.5
    };

    Order order("23-04-2026");

    int choice;

    while(true)
    {
        cout<<"\n===== Welcome to Silpo =====\n";
        cout<<"\n=== MENU ===\n";
        cout<<"1 Add product\n";
        cout<<"2 Remove product\n";
        cout<<"3 Change quantity\n";
        cout<<"4 Change status\n";
        cout<<"5 Show order\n";
        cout<<"6 Save to file\n";
        cout<<"7 Load from file\n";
        cout<<"8 Exit\n";

        cin>>choice;

        if(choice==1)
        {
            for(int i=0;i<names.size();i++)
            {
                cout<<i+1<<". "
                    <<names[i]
                    <<" $"
                    <<prices[i]
                    <<endl;
            }

            int id,qty;

            cin>>id;
            cin>>qty;

            order.addProduct(
                Product(
                    names[id-1],
                    prices[id-1],
                    qty
                )
            );
        }

        else if(choice==2)
        {
            string name;

            cout<<"Product name:";
            cin>>name;

            order.removeProduct(name);
        }

        else if(choice==3)
        {
            string name;
            int qty;

            cout<<"Product:";
            cin>>name;

            cout<<"New quantity:";
            cin>>qty;

            order.changeQuantity(
                name,
                qty
            );
        }

        else if(choice==4)
        {
            int s;

            cout<<"0 Pending\n1 Completed\n2 Cancelled\n";
            cin>>s;

            order.setStatus(
                (Status)s
            );
        }

        else if(choice==5)
        {
            order.print();
        }

        else if(choice==6)
        {
            order.saveToFile(
                "order.txt"
            );
            cout<<"Saved!\n";
        }

        else if(choice==7)
        {
            order.loadFromFile(
                "order.txt"
            );
            cout<<"Loaded!\n";
        }

        else if(choice==8)
            break;
    }
}