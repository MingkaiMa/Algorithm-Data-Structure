
BST* Successor(BST* x)
{
    if(x->right != NULL)
        return Minimum(x->right);

    BST* y = x->parent;

    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
}