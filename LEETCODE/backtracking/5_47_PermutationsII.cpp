/*

https://leetcode.com/problems/permutations-ii/
47_PermutationsII

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/

class Solution {
public:
    vector<vector<int>> res;
    
    void helper(int index, vector<int> nums)
    {
        if(index == nums.size())
        {
            res.push_back(nums);
        }
        
        for(int i=index;i<nums.size();i++)
        {
            if(i != index && nums[index] == nums[i])
            {
                continue;
            }
            swap(nums[i], nums[index]);
            helper(index+1, nums);    
            
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(0, nums);
        
        return res;
    }
};
