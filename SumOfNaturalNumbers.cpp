#include <iostream>

int main(){
    int num;
    std::cout<<"Enter a positive integer: ";
    std::cin>>num;
    std::cout<<"The sum of "<<num<<" natural numbers is: "<<(num*(num+1))/2<<std::endl;
}