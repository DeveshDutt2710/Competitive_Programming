/*

https://leetcode.com/problems/binary-tree-right-side-view/

199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    vector<int> leftSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int l = Q.size();
            for(int i=1;i<=l;i++)
            {
                TreeNode* temp = Q.front();
                Q.pop();
                if(i==1)
                {
                    res.push_back(temp->val);
                }
                if(temp->left)
                {
                    Q.push(temp->left);
                }
                if(temp->right)
                {
                    Q.push(temp->right);
                }
            }
        }
        return res;
        
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int l = Q.size();
            for(int i=1;i<=l;i++)
            {
                TreeNode* temp = Q.front();
                Q.pop();
                if(i==l)
                {
                    res.push_back(temp->val);
                }
                if(temp->left)
                {
                    Q.push(temp->left);
                }
                if(temp->right)
                {
                    Q.push(temp->right);
                }
            }
        }
        return res;
        
    }
};