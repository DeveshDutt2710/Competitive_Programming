/*
https://leetcode.com/problems/balanced-binary-tree/

110_BalancedBinaryTree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
    bool ans;
    int checkBalance(TreeNode* root){
        if(!root)
            return 0;
        if(!ans)
            return 0;
        int leftSubTree = checkBalance(root->left);
        int rightSubTree = checkBalance(root->right);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root){
        ans = true;
        int temp = checkBalance(root);
        return ans;
    }
};