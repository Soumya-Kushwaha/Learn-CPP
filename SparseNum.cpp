/*
Given a number N. The task is to check whether it is sparse or not.
A number is said to be a sparse number if no two or more 
consecutive bits are set in the binary representation.
*/

#include <bits/stdc++.h>

bool checkSparse(int n)
{
	// n is not sparse if there is set in AND of n and n/2
	if (n & (n>>1))
		return false;

	return true;
}

int main()
{
    int a;
    std::cout<<"N = ";
    std::cin>>a;
    std::cout << checkSparse(a) <<std::endl;
    return 0;
}
