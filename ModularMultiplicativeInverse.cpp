/*
Modular Multiplicative Inverse 
Problem Statement - 
Given two integers ‘a’ and ‘m’. The task is to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’.
Example:
a = 3
m = 11
Output: 4
Explanation: Since (4*3) mod 11 = 1, 4 
is modulo inverse of 3. One might think,
15 also as a valid output as "(15*3)
mod 11"  is also 1, but 15 is not in 
ring {0, 1, 2, ... 10}, so not valid.
*/

#include <bits/stdc++.h>

int ModularMultiplicationInverse(int s, int t){
    int i;
    for (i=0; i<t; i++){
        if ((i*s) % t == 1){
            break;
        }
    }
    return i;

}
int main(){
    int a, m;
    std::cout<<"a = ";
    std::cin>>a;
    std::cout<<"m = ";
    std::cin>>m;
    std::cout<<ModularMultiplicationInverse(a, m)<<std::endl;

}