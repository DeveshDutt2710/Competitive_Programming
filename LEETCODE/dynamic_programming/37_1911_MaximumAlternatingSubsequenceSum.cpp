/*

1911_MaximumAlternatingSubsequenceSum

The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 7
Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
Example 2:

Input: nums = [5,6,7,8]
Output: 8
Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.
Example 3:

Input: nums = [6,2,1,2,4,5]
Output: 10
Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/


// Recursive Intuition
// At a each given index, we can either choose this element and call the next index with an opposite sign.
// Or we can not choose this element and call the next index with the same sign as the one which was passed to current index.
// The answer now will simply be the max of these returned two values.
// We use isPos to signify isPositive sign, which, if false, will mean that sign is negative.
// Adding Memoization
// We observe that in each function call, only two variables change: isPos & the index i.
// Hence, as we're making choices at each step, which can end up leading to the same subproblem in further steps, we must optimize our approach by maintaining a 2-D DP table of dimensions 2, (nums).size, which at max, can be 10^5.
// Thus, we now simply add memoization with the traditional intial value = -1 approach.



class Solution {
public:
    long long dp[2][100001];
    long long util(int i, vector<int>&nums, bool isPos){
        if(i>=nums.size())return 0;
        if(dp[isPos][i]!=-1)return dp[isPos][i];
        long long curr = (isPos?nums[i]:-1*nums[i]);
        return dp[isPos][i] = max(curr + util(i+1, nums, !isPos), util(i+1, nums, isPos));
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return util(0, nums, true);
    }
};