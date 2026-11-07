#include <iostream>

class Trade {
private:
    double* price;

public:
    // 1. Normal Constructor
    Trade(double p) {
        price = new double(p);
        std::cout << "[Constructed] Built vault for: " << *price << std::endl;
    }

    // 2. Destructor
    ~Trade() {
        if (price == nullptr) {
            std::cout << "[Destructor] Vault was empty. Nothing to delete." << std::endl;
        }
        else {
            std::cout << "[Destructor] Blew up vault holding: " << *price << std::endl;
            delete price;
        }
    }

    // 3. Copy Constructor (The Slow Deep Copy)
    Trade(const Trade& other) {
        price = new double(*(other.price));
        std::cout << "[Copy Constructor] SLOW DEEP COPY completed." << std::endl;
    }

    // 4. Move Constructor (The Fast Heist)
    Trade(Trade&& other) {
        // Step 1: Steal the map to the vault (Nanosecond operation)
        price = other.price;

        // Step 2: Leave the victim with a blank map so they don't delete our vault!
        other.price = nullptr;

        std::cout << "[Move Constructor] FAST HEIST: Stole the vault and emptied the victim!" << std::endl;
    }

    // 5. Move Assignment Operator (The Overwrite Heist)
    Trade& operator=(Trade&& other) {
        if (this == &other) {
            return *this;
        }

        // Step 1: Destroy our old vault to prevent memory leaks
        delete price;

        // Step 2: Steal the victim's map
        price = other.price;

        // Step 3: Empty the victim's map so they don't delete our stolen vault
        other.price = nullptr;

        std::cout << "[Move Assignment] Destroyed old vault, stole the new one!" << std::endl;

        return *this;
    }
    
    // Safe Print Method
    void printStatus(const std::string& name) {
        if (price == nullptr) {
            std::cout << name << " status: [EMPTY - Pointer is nullptr]" << std::endl;
        } else {
            std::cout << name << " status: [Vault contains: " << *price << "]" << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Creating Trade 1 ---" << std::endl;
    Trade trade1(150.75);

    std::cout << "\n--- Creating Trade 2 (Blank) ---" << std::endl;
    Trade trade2(0.0);

    std::cout << "\n--- MEMORY CHECK BEFORE HEIST ---" << std::endl;
    trade1.printStatus("Trade 1");
    trade2.printStatus("Trade 2");

    std::cout << "\n--- Overwriting Trade 2 by robbing Trade 1 ---" << std::endl;
    trade2 = std::move(trade1); // This triggers the Move Assignment!

    std::cout << "\n--- MEMORY CHECK AFTER HEIST ---" << std::endl;
    trade1.printStatus("Trade 1");
    trade2.printStatus("Trade 2");

    std::cout << "\n--- main() ending ---" << std::endl;
    return 0;
}