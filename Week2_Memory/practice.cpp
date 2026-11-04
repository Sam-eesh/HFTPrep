
#include <iostream>

int main() {
    int stock_price = 150;

    std::cout << "The value of stock price is: " << stock_price << std::endl;
    std::cout << "The MEMORY ADDRESS of stock_price is: " << &stock_price << std::endl;

    // 1. Create a pointer to store the memory address
    int* price_ptr = &stock_price;

    // 2. Print the pointer itself (it should match the memory address)
    std::cout << "The value inside the pointer is: " << price_ptr << std::endl;

    // 3. Dereference the pointer to see the actual data it points to
    std::cout << "The data the pointer is POINTING TO is: " << *price_ptr << std::endl;

    // 4. Change the stock price USING the pointer (Zero-Copy modification)
    *price_ptr = 200;
    std::cout << "The NEW value of stock_price is: " << stock_price << std::endl;

    return 0;
}