/*

1650 - Lowest Common Ancestor of a Binary Tree III
Posted on June 6, 2020 · 1 minute read
Formatted question description: https://leetcode.ca/all/1650.html

1650_LowestCommonAncestorofBinaryTreeIII
Level
Medium

Description
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
*/



class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p;
        Node* b = q;
        while(a != b) {
            a = a == nullptr ? q : a->parent;
            b = b == nullptr ? p : b->parent;  
        }
        return a;
    }
};