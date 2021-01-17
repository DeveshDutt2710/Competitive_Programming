//Time Complexity of the above implementation is O(n Log n). 
//Note that the above implementation uses a map which is implemented using self-balancing BST.


//We can reduce the time complexity to O(n) using unordered_map. 
//To print nodes in the desired order, we can have 2 variables denoting
//min and max horizontal distance. 
//We can simply iterate from min to max horizontal distance and
//get corresponding values from Map. So it is O(n)

//Auxiliary Space: O(n) 

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *node=new Node();
    node->key=key;
    node->left=node->right=NULL;
    return node;
}

void printVerticalOrder(Node* root)
{
    if (!root)
        return;
 
    map<int, vector<int> > m;
    int hd = 0;
    
    queue<pair<Node*, int> > que;
    que.push(make_pair(root, hd));
 
    while (!que.empty()) {
        pair<Node*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node* node = temp.first;
 
        m[hd].push_back(node->key);
 
        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
 
    map<int, vector<int> >::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
 
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(12);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}