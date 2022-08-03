/*
A prime number is a number which is only divisible by 1 and itself.
Given number N check if it is prime or not.
*/

#include <bits/stdc++.h>

int Prime(int n){
    int count = 0;
    for (int i=2 ; i<n; i++){
        if (n%i == 0){
            count++;
            break;
        }
        else
            continue;
    }
    return count;
}

int main(){
    int N, x;
    std::cout<<"N = ";
    std::cin>>N;
    x = Prime(N);

    if (x == 1)
        std::cout<<"No"<<std::endl;
    else
        std::cout<<"Yes;"<<std::endl;
}