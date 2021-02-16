//Binary search tree basic implementation
struct node *search(struct node *root, int key)
{
    if(root==NULL || root->key==key)
    {
        return root;
    }
    
    if(root->key>key)
    {
        return search(root->left,key);
    }
    if(root->key < key)
    {
        return search(root->right, key);
    }
}