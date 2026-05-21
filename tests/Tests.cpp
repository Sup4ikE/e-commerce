#include <cassert>
#include <iostream>
#include "../src/Order.h"

using namespace std;

void testAddProduct()
{
    Order order;

    order.addProduct(Product("Milk", 40, 2));

    assert(order.getTotal() == 80);

    cout << "testAddProduct passed\n";
}

void testAddSameProduct()
{
    Order order;

    order.addProduct(Product("Milk", 40, 2));
    order.addProduct(Product("Milk", 40, 3));

    assert(order.getTotal() == 200);

    cout << "testAddSameProduct passed\n";
}

void testRemoveProduct()
{
    Order order;

    order.addProduct(Product("Milk", 40, 2));
    order.addProduct(Product("Bread", 20, 1));

    order.removeProduct("Milk");

    assert(order.getTotal() == 20);

    cout << "testRemoveProduct passed\n";
}

void testChangeQuantity()
{
    Order order;

    order.addProduct(Product("Milk", 50, 1));

    order.changeQuantity("Milk", 5);

    assert(order.getTotal() == 250);

    cout << "testChangeQuantity passed\n";
}

void testStatusChange()
{
    Order order;

    order.setStatus(COMPLETED);

    order.print();

    cout << "testStatusChange passed\n";
}

void testSaveLoad()
{
    Order order;

    order.addProduct(Product("Milk", 50, 2));
    order.addProduct(Product("Bread", 20, 1));

    order.setStatus(COMPLETED);

    order.saveToFile("test.txt");

    Order loaded;

    loaded.loadFromFile("test.txt");

    assert(loaded.getTotal() == 120);

    cout << "testSaveLoad passed\n";
}

void testEmptyOrder()
{
    Order order;

    assert(order.getTotal() == 0);

    cout << "testEmptyOrder passed\n";
}

int main()
{
    testAddProduct();

    testAddSameProduct();

    testRemoveProduct();

    testChangeQuantity();

    testStatusChange();

    testSaveLoad();

    testEmptyOrder();

    cout << "\nALL TESTS PASSED\n";
}