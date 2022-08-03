#include <bits/stdc++.h>

void Multiplication_Table(int input, int i){
    while (i>10)
        return;
    
    std::cout<<input<<" * "<<i<<" = "<<input*i<<std::endl;
    Multiplication_Table(input, i+1);
}

int main(){
    int input;
    std::cout<<"Enter a value to print multiplication table: ";
    std::cin>>input;

    Multiplication_Table(input, 1);

    return 0;
}