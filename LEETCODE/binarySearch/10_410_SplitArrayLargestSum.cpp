/*
https://leetcode.com/problems/split-array-largest-sum/


410_SplitArrayLargestSum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.
*/


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty() || m==0) return 0;
        size_t left = 0, right = 0;
        for(size_t n : nums) {
            left = max(left, n); 
            right += n; 
        }
        if(m == nums.size()) 
            return left;
        if(m == 1) 
            return right;
        while(left != right) 
        {
            size_t mid = (left + right) / 2;
            size_t curr_bagsize = 0, curr_m = 1;
            
            for(auto n : nums) 
            {
                if(curr_bagsize + n > mid) 
                {
                    curr_m++; 
                    curr_bagsize = 0;
                }
                curr_bagsize += n;
            } 
            if(curr_m > m) 
                
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
