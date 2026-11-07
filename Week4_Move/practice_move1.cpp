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
};

int main() {
    std::cout << "--- Creating Trade 1 ---" << std::endl;
    Trade trade1(150.75);

    std::cout << "\n--- Moving Trade 1 into Trade 2 ---" << std::endl;
    // std::move() casts trade1 to an && (an object ready to be robbed)
    Trade trade2 = std::move(trade1);

    std::cout << "\n--- main() ending ---" << std::endl;
    return 0;
}