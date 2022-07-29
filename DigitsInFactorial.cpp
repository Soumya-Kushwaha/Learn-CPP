/*
Problem Statement - 
Given an integer N. Find the number of digits that appear in its factorial. 
Factorial is defined as, factorial(n) = 1*2*3*4……..*N and factorial(0) =1.
Example: 
Input: N = 5
Output: 3
Explanation: Factorial of 5 is 120.
Number of digits in 120 is 3 (1, 2, and 0)                
Input: N = 120
Output: 199
Explanation: The number of digits in
120! is 199    
*/

#include <bits/stdc++.h>

int DigitsInFactorial(int n){
    // no factorial for negative values
    if (n < 0)
        return 0;

    if (n <= 1)
        return 1;
    
    double digits = 0;
    for (int i=2; i<=n; i++)
        digits += log10(i);
    
    return ceil(digits);
}

int main(){
    int N;
    std::cout<<"N = ";
    std::cin>>N;
    std::cout<<DigitsInFactorial(N)<<std::endl;

}