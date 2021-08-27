/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

34_FindFirstandLastPositionofElementinSortedArray

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size(), mid, left, right;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
        }
        left = start;
        start = 0, end = nums.size();
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        right = start;
        return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
    }
};