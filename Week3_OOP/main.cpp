#include <iostream>

class OrderBook {
private:
    int* max_order;
    public:
    OrderBook(int Limit) {
        max_order = new int(Limit);
        std::cout << "OrderBook created in memory." << std::endl;
        std::cout << "Allocted heap memory for max order: " << *max_order<< std::endl;
    }
    ~OrderBook() {
        delete max_order;
        std::cout << "Freed max_order memory from heap "<< std::endl;
        std::cout << "OrderBook destroyed and cleaned up." << std::endl;
    }
    int getLimit() {
        return *max_order;
    }


};

int main() {
    OrderBook my_book(50000);
    int vault_size = my_book.getLimit();
    std::cout << "The vault holds "<<vault_size<<" which means half the vault is "<<(vault_size/2)<<std::endl;
}