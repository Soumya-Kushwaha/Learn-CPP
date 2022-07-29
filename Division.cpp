/*
#include<iostream>

int main(){
    int divd, divs,quo, rem;
    std::cout<<"Please enter the dividend: ";
    std::cin>>divd;
    std::cout<<"Please enter the divisor: ";
    std::cin>>divs;
    quo = divd / divs;
    rem = divd % divs;
    std::cout<<"The quotient of the division is: "<<quo<<std::endl;
    std::cout<<"The remainder of the dividion is: "<<rem<<std::endl;
    return 0;
}
*/
//------------------------------------OR-----------------------------------------

#include <iostream>

int main(){
    int divd, divs, temp = 0, quo, rem;
    std::cout<<"Please enter two numbers to perform division: ";
    std::cin>>divd>>divs;

    if (divs>divd){
        temp = divd;
        divd = divs;
        divs = temp;
    }
    
    quo = divd / divs;
    rem = divd % divs;

    std::cout<<"The quotient and remainder of the division are "<<quo<<" and "<<rem<<"  respectively."<<std::endl;
}