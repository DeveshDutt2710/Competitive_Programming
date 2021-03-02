#include <bits/stdc++.h>
using namespace std;

int isMultipleOf3(int n)
{
    int odd_count = 0;
    int even_count = 0;
    
    if(n<0)
    {
        n=-n;
    }
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 0;
    }
    
    while(n)
    {
        if(n&1)
        {
            odd_count++;
        }
        if(n&2)
        {
            even_count++;
        }
        n=n>>2;
    }
    
    return isMultipleOf3(abs(odd_count-even_count));
}

int main() 
{ 
    int num = 24; 
    if (isMultipleOf3(num)) 
        printf("%d is multiple of 3", num); 
    else
        printf("%d is not a multiple of 3", num); 
    return 0; 
}
