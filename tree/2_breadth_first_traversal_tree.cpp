#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
};

void printGivenLevel(Node *root,int level);
int height(Node *node);
Node *newNode(int data);


void printLevelOrder(Node* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
} 


void printGivenLevel(Node *root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->data<<" ";
    }
    else if(level>1){
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

int height(Node *node){
    if(node==NULL){
        return 0;
    }
    else{
        int lheight=height(node->left);
        int rheight=height(node->right);
        
        if(lheight>rheight){
            return(lheight+1);
        }
        else return(rheight+1);
    }
}


Node *newNode(int data){
    Node *node=new Node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    
    return(node);
}

int main(){
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    
    cout<<"level order traversal of binary tree is \n";
    printLevelOrder(root);
    
    return 0;
}