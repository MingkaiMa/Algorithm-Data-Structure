
BST* Minimum(BST* x)
{
    while(x->left != NULL)
        x = x->left;

    return x;
}