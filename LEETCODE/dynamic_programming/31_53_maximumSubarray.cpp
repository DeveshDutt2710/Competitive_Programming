/*
https://leetcode.com/problems/maximum-subarray/

53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
*/

class Solution {
public: 
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        
        int curSum = nums[0];
        int maxSum = nums[0];
        
        for(int i=1;i<n;i++){
            if(curSum+nums[i]<nums[i]) 
                curSum = nums[i];
            else 
                curSum += nums[i];
            maxSum = max(maxSum,curSum); 
        }
        return maxSum;
    }
};


int maxSubArray(vector<int>& nums) {
         
         int n = nums.size();
         int sum = nums[0];
         int maxsum = nums[0];
         for(int i = 1 ; i < n ; i++){
             if(sum>=0)
                 sum+=nums[i];
             else
                 sum = nums[i];
             if(sum>maxsum){
                 maxsum = sum;
             }
         }
         return maxsum;
     }