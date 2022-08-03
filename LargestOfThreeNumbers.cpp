#include <iostream>

int main(){
    float n1, n2, n3;

    std::cout << "Enter three numbers: ";
    std::cin >> n1 >> n2 >> n3;

    if(n1 >= n2 && n1 >= n3)
        std::cout << "Largest number: " << n1;

    if(n2 >= n1 && n2 >= n3)
        std::cout << "Largest number: " << n2;
    
    if(n3 >= n1 && n3 >= n2)
        std::cout << "Largest number: " << n3;
  
    return 0;
}