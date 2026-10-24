#include <iostream>
#include <cmath>


int main() {
    double a,b;
    char symbol;

    std::cout<<"enter the first number \n";
    std::cin>>a;
    std::cout<<"enter the operation \n";
    std::cin>>symbol;
    std::cout<<"enter the second number\n";
    std::cin>>b;

    if (symbol == '+') {
        std::cout<<"you chose addition and the result on adding numbers : \n"<<a+b<< std::endl;
    }
    else if (symbol == '-'){
        std::cout<<"you chose subtaction and the result on subtracting numbers : \n"<<a-b<< std::endl;
    }
    else if (symbol == '*' ) {
        std::cout<<"you chose multiplication and the result on multiplying numbers : \n"<<a*b<< std::endl;
    }
    else if (symbol == '/') {
        if (b == 0) {std::cout<<"Error: Division by zero is undefined. \n"<< std::endl;}
        else{ std::cout<<"you chose division and the result on dividing numbers : \n"<<a/b<< std::endl;
        }
    }
    else if (symbol == '^') {
        std::cout<<"you chose power and the result of power is: "<< pow(a,b)<< std::endl;
    }
    else if (symbol == 'r') {
        if (a < 0 && (int)b % 2 == 0) {
            std::cout << "Error: Even root of a negative number is undefined.\n";
        } else {
            std::cout<<"you chose root and the second number'th root of first number is : "<< pow(a,1.0/b)<< std::endl;
        }
    }
    else if (symbol == 'l') {
        if ( a>0 && b>0 && b!=1) {
                std::cout << "you chose logarithm and the log of a base b is: "<< log(a)/log(b) << std::endl;
        }
        else {
                std::cout<<"you chose invalid numbers, these can't be used in logarithm";
        }
    }
    else {
        std::cout<<"invalid symbol, try again"<<std::endl;
    }


    return 0;
}