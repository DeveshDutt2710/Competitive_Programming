/*

https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

1372_LongestZigZagPathinBinaryTree

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.


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
    int maxStep = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxStep;
    }
    void dfs(TreeNode* root, bool isLeft, int step) {
        if (!root)
        {
            return;
        }
        
        maxStep = max(maxStep, step);
        if (isLeft) 
        {
            dfs(root->left, false, step + 1);
            dfs(root->right, true, 1); 
        } 
        else 
        {
            dfs(root->right, true, step + 1);
            dfs(root->left, false, 1); 
        }
    }
};