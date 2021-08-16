/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/

1448_CountGoodNodesinBinaryTree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 
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
    int count = 0;
    void solve(TreeNode* root, int max)
    {
        if(!root)
        {
            return;
        }
        if(root->val >= max)
        {
            count++;
            max = root->val;
        }
        solve(root->left,max);
        solve(root->right,max);
    }
    int goodNodes(TreeNode* root) {
        solve(root,root->val);
        return count;
        
    }
};