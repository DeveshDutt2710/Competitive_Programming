/*
https://www.geeksforgeeks.org/find-count-of-singly-subtrees/

FindCountofSingleValuedSubtrees

Given a binary tree, write a program to 
count the number of Single Valued Subtrees. 
A Single Valued Subtree is one in which all the nodes have same value. 
Expected time complexity is O(n).
*/




#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node* left, *right;
};
 
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}
 
bool countSingleRec(Node* root, int &count)
{
    if (root == NULL)
       return true;
 
    bool left = countSingleRec(root->left, count);
    bool right = countSingleRec(root->right, count);
 
    if (left == false || right == false)
       return false;
 
    if (root->left && root->data != root->left->data)
        return false;
 
    if (root->right && root->data != root->right->data)
        return false;
 
    count++;
    return true;
}

int countSingle(Node* root)
{
    int count = 0;
    countSingleRec(root, count);

    return count;
}
 

int main()
{
    Node* root        = newNode(5);
    root->left        = newNode(4);
    root->right       = newNode(5);
    root->left->left  = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);
 
    cout << "Count of Single Valued Subtrees is "
         << countSingle(root);
    return 0;
}