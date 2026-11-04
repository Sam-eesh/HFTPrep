#include <iostream>
#include <string>

struct order {
    std::string ticker;
    double price;
    int volume;
};

void updateVolume(order& ord, int new_vol) {
    ord.volume = new_vol;
}

int main() {
    order my_order;
    my_order.ticker="TSLA";
    my_order.price=250.50;
    my_order.volume=100;
    std::cout<< "buying "<<my_order.volume<<" shares of "<< my_order.ticker <<" at "<<my_order.price<<std::endl;

    updateVolume(my_order , 999);

    order my_order2;
    my_order2.ticker="AAPL";
    my_order2.price=150.00;
    my_order2.volume=200;
    std::cout<< "buying "<<my_order2.volume<<" shares of "<< my_order2.ticker <<" at "<<my_order2.price<<std::endl;

    updateVolume(my_order2, 999);
    std::cout<<"UPDATED : Buying "<<my_order2.volume<<" shares of "<<my_order2.ticker<<" at "<<my_order2.price<<std::endl;

    return 0;
}