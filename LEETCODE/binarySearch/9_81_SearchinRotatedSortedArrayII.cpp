/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

81_SearchinRotatedSortedArrayII

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
*/


class Solution {
public:
    bool search(vector<int>& A, int target) {
        if (A.empty()) 
            return false;
        
        int low = 0, high = A.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;    
            
            if (A[mid] == target) 
                return true;
            
            if (A[low] < A[mid]) 
            {
                if (A[low] <= target && target < A[mid]) 
                {
                    high = mid - 1;
                } 
                else 
                {
                    low = mid + 1;
                }
            } else if (A[mid] < A[high]) 
            {
                if (A[mid] < target && target <= A[high]) 
                {
                    low = mid + 1;
                } 
                else 
                {
                    high = mid - 1;
                }
            } 
            else 
            {
                if (A[low] == A[mid]) 
                    low++;
                if (A[mid] == A[high]) 
                    high--;
            }
        }
        
        return A[low] == target ? true : false;
    }
};