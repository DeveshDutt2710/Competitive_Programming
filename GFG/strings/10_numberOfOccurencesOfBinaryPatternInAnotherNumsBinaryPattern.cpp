// C++ program to find the number of times
// pattern p occurred in binary representation
// on n.


#include <bits.stdc++.h>
using namespace std;

int countPattern(int n,string pat)
{
    int pattern_int = 0;
    int power_two = 1;
    
    int all_ones = 0;
    
    for(int i=pat.length()-1;i>=0;i--)
    {
        int current_bit = pat[i]-'0';
        
        pattern_int+= (power_two*current_bit);
        all_ones += power_two;
        power_two *= 2;
    }
    
    int count=0;
    
    while(n && n>=pattern_int)
    {
        if(n & all_ones == pattern_int)
        {
            count++;
        }
        
        n = n>>1;
    }
    
    return count;
}
