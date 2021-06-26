/*
https://leetcode.com/problems/maximum-average-subarray-i/

643_MaximumAverageSubarrayI

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/

class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int n = a.size();
        double sum = 0;
        double max_sum = 0;
        for(int i=0;i<k;i++)
        {
            sum += a[i];
        }
        max_sum = sum;
        for(int i=1;i<n-k+1;i++)
        {
            sum += a[i+k-1] - a[i-1];
            max_sum = max(max_sum,sum);
        }
        
        return max_sum / k;
    }
};