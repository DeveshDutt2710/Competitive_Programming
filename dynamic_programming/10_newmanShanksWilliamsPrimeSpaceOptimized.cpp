//program to print Nth newman-shanks-williams prime

#include <iostream> 
using namespace std; 
  
int nswp(int n) 
{ 
      
    if(n == 0 || n == 1)  
    { 
        return 1; 
    } 
      
    int a = 1, b = 1; 
      
    for(int i = 2; i <= n; ++i) 
    { 
        int c = 2*b+a; 
        a = b; 
        b = c; 
    } 
    return b; 
} 
int main() 
{ 
    int n = 5; 
    cout << nswp(n); 
    return 0; 
}