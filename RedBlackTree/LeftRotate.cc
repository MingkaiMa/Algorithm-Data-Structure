
void leftRotate(BST* T, BST* x)
{
    BST* y = x->right;
    x->right = y->left;

    if(y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if(x->parent == NULL)
        T = y;

    else if(x == x->parent->left)
        x->parent->left = y;

    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}