#include <iostream>

class Trade {
private:
    double* price; // The Vault (Heap Memory)

public:
    // ---------------------------------------------------------
    // 1. NORMAL CONSTRUCTOR (Birth)
    // ---------------------------------------------------------
    Trade(double initial_price) {
        price = new double(initial_price);
        std::cout << "[Constructor] Trade created with price: " << *price << std::endl;
    }

    // ---------------------------------------------------------
    // 2. THE DESTRUCTOR (Death) - RULE 1 OF 3
    // ---------------------------------------------------------
    ~Trade() {
        delete price;
        std::cout << "[Destructor] Memory safely freed." << std::endl;
    }

    // ---------------------------------------------------------
    // 3. COPY CONSTRUCTOR (The Deep Clone) - RULE 2 OF 3
    // Triggered when: Trade t2 = t1;
    // ---------------------------------------------------------
    Trade(const Trade& other) {
        // Build a brand new vault and copy the data inside
        price = new double(*(other.price));
        std::cout << "[Copy Constructor] Deep clone created!" << std::endl;
    }

    // ---------------------------------------------------------
    // 4. COPY ASSIGNMENT OPERATOR (The Overwrite) - RULE 3 OF 3
    // Triggered when: t2 = t1; (on an already existing object)
    // ---------------------------------------------------------
    Trade& operator=(const Trade& other) {
        // Step 1: Prevent self-assignment (t1 = t1;)
        if (this == &other) {
            return *this; // return ourself immediately
        }

        // Step 2: Delete our old vault to prevent memory leaks
        delete price;

        // Step 3: Build a new vault and copy the data
        price = new double(*(other.price));

        std::cout << "[Assignment Operator] Old memory destroyed, new clone built!" << std::endl;

        // Step 4: Return ourself so main() can chain assignments
        return *this;
    }

    // Getter Method
    double getPrice() {
        return *price;
    }
};

int main() {
    std::cout << "--- 1. Testing Normal Constructor ---" << std::endl;
    Trade apple_trade(150.75);

    std::cout << "\n--- 2. Testing Copy Constructor ---" << std::endl;
    Trade cloned_trade = apple_trade; // This calls the Copy Constructor

    std::cout << "\n--- 3. Testing Copy Assignment Operator ---" << std::endl;
    Trade blank_trade(0.0); // Create a blank trade first
    blank_trade = apple_trade; // This overwrites it, calling the Operator=

    std::cout << "\n--- 4. End of main(), Destructors will run ---" << std::endl;
    return 0; // 3 trades exist in main, so the Destructor will run 3 times
}