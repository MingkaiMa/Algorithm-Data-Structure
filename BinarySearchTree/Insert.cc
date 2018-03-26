
void Insert(BST* root, BST* z)
{
    BST* y = NULL;
    BST* x = root;

    while(x != NULL)
    {
        y = x;

        if(z->val < x->val)
            x = x->left;

        else
            x = x->right;
    }

    y = z->parent;

    if(y == NULL)
        root = z;

    else if(z->val < y->val)
        y->left = z;

    else
        y->right = z;
}