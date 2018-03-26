
BST* Search(BST* root, int value)
{
    if(root == NULL || k == root->val)
        return root;


    if value < root->val
        return Search(root->left, value);

    return Search(root->right, value);
}