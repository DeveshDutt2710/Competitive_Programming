#include <bits/stdc++.h>
using namespace std;

unsigned getNthUglyNo(unsigned n){
    unsigned ugly[n];
    unsigned i2=0,i3=0,i5=0;
    unsigned next_multiple_2=2;
    unsigned next_multiple_3=3;
    unsigned next_multiple_5=5;
    unsigned next_ugly_num=1;
    
    ugly[0]=1;
    for(int i=1;i<n;i++){
        next_ugly_num=min(next_multiple_2,min(next_multiple_3,next_multiple_5));
        ugly[i]=next_ugly_num;
        
        if(next_ugly_num==next_multiple_2){
            i2+=1;
            next_multiple_2=ugly[i2]*2;
        }
        if(next_ugly_num==next_multiple_3){
            i3+=1;
            next_multiple_3=ugly[i3]*3;
        }
        if(next_ugly_num==next_multiple_5){
            i5+=1;
            next_multiple_5=ugly[i5]*5;
        }
    }
    return next_ugly_num;
}

int main() 
{ 
    int n = 150; 
    cout << getNthUglyNo(n); 
    return 0; 
} 

//time complexity : O(n)
//space complexity : O(n)

