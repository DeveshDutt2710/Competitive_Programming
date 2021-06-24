//program to print Nth newman-shanks-williams prime

#include <bits/stdc++.h>

using namespace std;

int nswp(int n)
{
    if(n==0||n==1){
        return 1;
    }
    return 2*nswp(n-1)+nswp(n-2);
}


int main() 
{ 
    int n = 5; 
  
    cout << nswp(n) << endl; 
    return 0; 
}