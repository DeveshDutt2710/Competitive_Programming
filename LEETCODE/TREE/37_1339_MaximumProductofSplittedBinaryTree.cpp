/*
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

1339_MaximumProductofSplittedBinaryTree

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.
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
    long totalSum,sub, maxproduct = 0;
    
    int sum(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        sub = root->val + sum(root->left)+sum(root->right);
        
        maxproduct = max(maxproduct,(totalSum-sub)*sub);
        return sub;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        totalSum = sum(root);
        sum(root);
        
        return maxproduct%1000000007;
    }
};