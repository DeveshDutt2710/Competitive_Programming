/*
Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n). 
Auxiliary Space: O(n), due to the stack space during recursive call.  

*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

Node *newNode(int item)
{
    Node *temp=new Node();
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

void leftViewUtil(Node *root, int level, int *max_level)
{
    if(root==NULL)
    {
        return;
    }
    
    if(*max_level<level)
    {
        printf("%d\t", root->data);
        *max_level=level;
    }
    
    leftViewUtil(root->left,level+1,max_level);
    leftViewUtil(root->right,level+1,max_level);
}

void leftView(Node *root)
{
    int max_level=0;
    leftViewUtil(root,1,&max_level);
}

int main()
{
    Node *root=newNode(12);
    root->left=newNode(10);
    root->right=newNode(30);
    root->right->left=newNode(25);
    root->right->right=newNode(40);
    
    leftView(root);
    
    return 0;
}