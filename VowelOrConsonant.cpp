#include <iostream>
#include <string.h>

int main(){
    char alphabet; 
    std::cout<<"Enter an alphabet: ";
    std::cin>>alphabet; //inputs the alphabet

    char input = tolower(alphabet); // convert to lowercase to decrease conditional statu=ements

    if((input == 'a') || (input == 'e') || (input == 'i') || (input == 'o') || (input == 'u' ))
        std::cout<<alphabet<<" is a vowel."<<std::endl;
    else
        std::cout<<alphabet<<" is a consonant."<<std::endl;
}