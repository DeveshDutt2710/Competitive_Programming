/*
https://leetcode.com/problems/find-greatest-common-divisor-of-array/

1979_FindGreatestCommonDivisorofArray

Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/


class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int a=nums[0];
        int b=nums[n-1];
        
        while(a!=0)
        {
            int c = a;
            a = b%a;
            b=c;
        }
        return b;
    }
};