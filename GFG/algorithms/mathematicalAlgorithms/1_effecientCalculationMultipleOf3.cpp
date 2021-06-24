/*

Time Complexity: O(logn)


1) Get count of all set bits at odd positions (For 23 it’s 3).
2) Get count of all set bits at even positions (For 23 it’s 1).
3) If difference of above two counts is a multiple of 3 then number is also a multiple of 3.

(For 23 it’s 2 so 23 is not a multiple of 3)


PROOF:
Above can be proved by taking the example of 11 in decimal numbers. (In this context 11 in decimal numbers is same as 3 in binary numbers)
If difference between sum of odd digits and even digits is multiple of 11 then decimal number is multiple of 11. Let’s see how.

Let’s take the example of 2 digit numbers in decimal
AB = 11A -A + B = 11A + (B – A)
So if (B – A) is a multiple of 11 then is AB.

Let us take 3 digit numbers.

ABC = 99A + A + 11B – B + C = (99A + 11B) + (A + C – B)
So if (A + C – B) is a multiple of 11 then is (ABC)

Let us take 4 digit numbers now.
ABCD = 1001A + D + 11C – C + 999B + B – A
= (1001A – 999B + 11C) + (D + B – A -C )
So, if (B + D – A – C) is a multiple of 11 then is ABCD

*/

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
