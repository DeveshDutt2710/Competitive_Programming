/*
https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

1985_FindtheKthLargestIntegertheArray

You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

*/


class Solution {
public:
    
    struct comp
    {
        bool operator()(const string &a, const string &b)
        {
            return a.length()==b.length() ? (a>b) : a.length()>b.length();
        }    
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,comp>pQ;
        
        for(auto &t : nums)
        {
            pQ.push(t);
            
            if(pQ.size()>k)pQ.pop();
        }
        
        return pQ.top();
    }
};