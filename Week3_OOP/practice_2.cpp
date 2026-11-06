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

    // 4. Copy Assignment Operator (For overwriting: b2 = b1;)
    OrderBook& operator=(const OrderBook& other) {
        // Step 1: Prevent self-assignment (book1 = book1)
        if (this == &other) {
            return *this;
        }

        // Step 2: Delete our old vault so it doesn't leak
        delete max_order;

        // Step 3: Build a brand new vault and copy the data
        max_order = new int(*(other.max_order));

        std::cout << "DEEP ASSIGNMENT: Old vault destroyed, new clone vault built!" << std::endl;

        // Step 4: Return ourselves
        return *this;
    }

    int getLimit() {
        return *max_order;
    }
};

int main() {
    std::cout << "--- Creating Book 1 ---" << std::endl;
    OrderBook book1(50000);

    std::cout << "\n--- Creating Book 2 (Blank) ---" << std::endl;
    OrderBook book2(100);

    std::cout << "\n--- Overwriting Book 2 with Book 1 ---" << std::endl;
    book2 = book1; // This now safely calls operator=

    std::cout << "\n--- main() is ending, destructors will run ---" << std::endl;
    return 0;
}