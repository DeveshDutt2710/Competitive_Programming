/*

https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

559_MaximumDepthofNaryTree
*/




/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
        {
            return 0;
        }
        int count = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            count++;
            int l = q.size();
            for(int i=0;i<l;i++)
            {
                Node* temp = q.front();
                q.pop();
                for(int j=0;j<temp->children.size();j++)
                {
                    q.push(temp->children[j]);
                }
            }
        }
        return count;
        
    }
};