/*
https://leetcode.com/problems/longest-univalue-path/

687_LongestUnivaluePath

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [5,4,5,1,1,5]
Output: 2
Example 2:


Input: root = [1,4,5,4,4,5]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.
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
    int dfs(TreeNode* root, int &lmax)
    {
        int l = (root->left) ? dfs(root->left,lmax):0;
        int r = (root->right) ? dfs(root->right,lmax) :0;
        
        int resl = (root->left && root->left->val == root->val)?l+1:0;
        int resr = (root->right && root->right->val == root->val)?r+1:0;
        
        lmax = max(lmax, resl+resr);
        
        return max(resl,resr);
        
    }
    int longestUnivaluePath(TreeNode* root) {
        int lmax = 0;
        
        if(root)
            dfs(root,lmax);
        return lmax;
        
    }
};