
#include <iostream> 

unsigned int countSetBitsUtil(unsigned int x); 

unsigned int countSetBits(unsigned int n) 
{ 
    int bitCount = 0;
  
    for (int i = 1; i <= n; i++) 
        bitCount += countSetBitsUtil(i); 
  
    return bitCount; 
} 

unsigned int countSetBitsUtil(unsigned int x) 
{ 
    if (x <= 0) 
        return 0; 
    return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2); 
} 

int main() 
{ 
    int n;
    std::cout<<"N = ";
    std::cin>>n;
    std::cout<<countSetBits(n); 
    return 0; 
} 