#include <iostream>

int main(){
    float a, b, sum;
    std::cout<<"Please enter two numbers: ";
    std::cin>>a>>b;
    sum = a + b;
    std::cout<<"The sum of "<<a<<" and "<<b<<" is: "<<sum<<std::endl;
    return 0;
}