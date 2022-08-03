/*
Given a number N and a bit number K, check if Kth bit of N is set or not. A bit is called set if it is 1. 
Position of set bit '1' should be indexed starting with 0 from the LSB side in binary representation of the number.
*/

#include <iostream>

void isKthBitSet(int n, int k)
{
    if ((n >> (k - 1)) & 1)
        std::cout << "Yes";
    else
        std::cout << "No";
}

// Driver code
int main()
{
	int n, k;
    std::cout<<"N = ";
    std::cin>>n;
    std::cout<<"K = ";
    std::cin>>k;
	isKthBitSet(n, k);
	return 0;
}
