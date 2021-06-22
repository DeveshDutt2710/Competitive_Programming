
/*

https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/submissions/

1022. Sum of Root To Leaf Binary Numbers

You are given the root of a binary tree where each node has a value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.

 

Example 1:


Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
Example 2:

Input: root = [0]
Output: 0
Example 3:

Input: root = [1]
Output: 1
Example 4:

Input: root = [1,1]
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    
    int convert_decimal(vector<int> v)
    {
        int n=0;
        for(int i=0;i<v.size();i++)
            n=n*2+v[i];
        return n;
    }
    
    void findpath(TreeNode* root,vector<int> t)
    {
        if(!root)return;
        t.push_back(root->val);
        if(!root->left && !root->right)ans+=convert_decimal(t);
        findpath(root->left,t);
        findpath(root->right,t);
    }
    
    int sumRootToLeaf(TreeNode* root) 
    {
        if(!root)return 0;
        vector<int> t;
        findpath(root,t);
        return ans;
    }
};








class Solution {
public:
    int sol=0;
    int sumRootToLeaf(TreeNode* root,int num=0) {
        if(!root)return 0;
        num *= 2;
        num+=root->val;
        if(!root->left&&!root->right)sol+=num;
        sumRootToLeaf(root->left,num);
        sumRootToLeaf(root->right,num);
        return sol;
    }
};