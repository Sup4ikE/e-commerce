cmake_minimum_required(VERSION 4.2)
project(e_commerce)

set(CMAKE_CXX_STANDARD 20)

# Спільний код
add_library(e_commerce_lib
        src/Order.h
        src/Order.cpp
        src/Product.h
        src/Product.cpp
)
target_include_directories(e_commerce_lib PUBLIC src)

# Основний застосунок
add_executable(e_commerce src/main.cpp)
target_link_libraries(e_commerce PRIVATE e_commerce_lib)

# Тести
add_executable(e_commerce_tests tests/Tests.cpp)
target_link_libraries(e_commerce_tests PRIVATE e_commerce_lib)