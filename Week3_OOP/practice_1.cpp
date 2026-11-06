//practice of copy constructor (b2=b1)

#include <iostream>

class OrderBook {
private:
    int* max_order;

public:
    // 1. Normal Constructor
    OrderBook(int Limit) {
        max_order = new int(Limit);
        std::cout << "OrderBook created. Vault size: " << *max_order << std::endl;
    }

    // 2. Destructor
    ~OrderBook() {
        delete max_order;
        std::cout << "Freed max_order memory from heap." << std::endl;
    }

    // 3. Copy Constructor (For creation: OrderBook b2 = b1;)
    OrderBook(const OrderBook& other) {
        max_order = new int(*(other.max_order));
        std::cout << "DEEP COPY CONSTRUCTOR: Created new clone vault!" << std::endl;
    }

    int getLimit() {
        return *max_order;
    }
};

int main() {
        std::cout << "--- Creating Book 1 ---" << std::endl;
        OrderBook book1(50000);

        std::cout << "--- Copying Book 1 into Book 2 ---" << std::endl;
        OrderBook book2 = book1; // THIS IS THE DANGEROUS SHALLOW COPY

        std::cout << "--- main() is ending, destructors will run ---" << std::endl;
        return 0;

}