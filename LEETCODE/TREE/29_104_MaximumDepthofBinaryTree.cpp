/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/

104_MaximumDepthofBinaryTree
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
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int depth = 0;
        depth =  max(depth, 1+maxDepth(root->left));
        depth = max(depth, 1+maxDepth(root->right));
                     
        return depth;
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};