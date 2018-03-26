

//  recursion
BST* Search(BST* root, int value)
{
    if(root == NULL || k == root->val)
        return root;


    if value < root->val
        return Search(root->left, value);

    return Search(root->right, value);
}



//  while loop to replace recursion

BST* Iterative_Search(BST* root, int value)
{
    while(x != NULL && value != root->val)
    {
        if(root->val > value)
            root = root->left;

        else
            root = root->right;

    }
    return root;
}