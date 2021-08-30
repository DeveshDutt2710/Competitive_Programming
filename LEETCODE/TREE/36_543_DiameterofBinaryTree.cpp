/*
https://leetcode.com/problems/diameter-of-binary-tree/

543_DiameterofBinaryTree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
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

    int height(TreeNode* root)
    {
        if(!root) return 0;

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        ans= max(ans,lHeight + rHeight);
        return 1+ max( lHeight , rHeight);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return ans;
    }
};