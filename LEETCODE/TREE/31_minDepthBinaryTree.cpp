/*

minDepthBinaryTree
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
    int minDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return 1 + (left && right ?min(left,right):max(left,right));
        
    }
};



class Solution {
public:
    int level = 0;
    int minDepth(TreeNode* root) {
        if(!root){ return 0;}
        
        queue<TreeNode*> q;
        int level = 0;
        
        q.push(root);
        while(!q.empty()){
            int breadth = q.size();
            level++;
            for(int i=0; i<breadth; i++){
                TreeNode* parent = q.front(); 
                q.pop();
                
                if(parent->left) q.push(parent->left);
                if(parent->right) q.push(parent->right);
                
                if(!parent->left && !parent->right) return level; 
            }
        }
        
        return level;
    }
};