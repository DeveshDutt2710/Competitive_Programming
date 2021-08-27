/*
https://leetcode.com/problems/find-the-duplicate-number/

287_FindtheDuplicateNumber

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int hare = nums[nums[0]], tortoise = nums[0];
        
        while(hare != tortoise)
        {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }
        
        tortoise = 0;
        while(hare != tortoise) {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};

