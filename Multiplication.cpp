#include <iostream>

int main(){
    int a,b, product;
    std::cout<<"Enter two numbers to perform multiplication: ";
    std::cin>>a>>b;
    product = a*b;
    std::cout<<"The product of "<<a<<" and "<<b<<" is: "<<product;
}