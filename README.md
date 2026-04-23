# Online Order Management System (C++)

University laboratory project written in C++ using STL and file handling.

## 📌 Description
This project simulates an online ordering system similar to basic e-commerce functionality.

Implemented features:
- Add products to order
- Remove products
- Change product quantity
- Set order date
- Change order status:
  - Pending
  - Completed
  - Cancelled
- Choose payment method:
  - Cash
  - Card
- Calculate total order price
- Save orders to file
- Load orders from file

## 🛠 Technologies
- C++
- STL (`vector`, `algorithm`)
- File I/O (`fstream`)
- OOP

## 📂 Project Structure
```text
Product.h / Product.cpp   - Product model
Order.h / Order.cpp       - Order logic
main.cpp                  - Menu-driven interface
```

## ▶️ Features Demonstrated
- Object-Oriented Programming
- Working with collections using STL
- File serialization/deserialization
- Menu-driven console application
- Basic order management logic

## Example Menu
```text
1 Add product
2 Remove product
3 Change quantity
4 Change status
5 Show order
6 Save to file
7 Load from file
8 Exit
```

## 🚀 Run
Compile:

```bash
g++ main.cpp Order.cpp Product.cpp -o app
```

Run:

```bash
./app
```

## 🎓 Purpose
Created as a university laboratory work to practice:
- STL containers
- File operations
- OOP in C++
- Real-world style console project implementation
