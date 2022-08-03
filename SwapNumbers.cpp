#include <iostream>

int main(){
    int a, b, temp;
    std::cout<<"Enter two numbers: ";
    std::cin>>a>>b;

    std::cout<<"BEFORE SWAPPING --"<<std::endl;
    std::cout<<"First number: "<<a<<std::endl;
    std::cout<<"Second number: "<<b<<std::endl;

    temp = a;
    a = b;
    b = temp;

    std::cout<<"\nAFTER SWAPPING --"<<std::endl;
    std::cout<<"First number: "<<a<<std::endl;
    std::cout<<"Second number: "<<b<<std::endl;

    return 0;
}