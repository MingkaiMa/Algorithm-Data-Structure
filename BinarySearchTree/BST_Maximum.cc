
BST* Maximum(BST* x)
{
    while(x->right != NULL)
        x = x->right;

    return x;
}