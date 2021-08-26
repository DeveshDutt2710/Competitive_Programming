/*
https://leetcode.com/problems/three-divisors/

1952_ThreeDivisors

Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.
*/


class Solution {
public:
    bool isThree(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                count++;
            
            if(count > 3)
                return false;
        }
        return count==3?true:false;
    }
};