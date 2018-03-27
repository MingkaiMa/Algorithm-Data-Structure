
void RB_Insert(BST* T, BST* z)
{
    BST* y = NULL;
    BST* x = T;

    while(x != NULL)
    {
        y = x;
        if(z->val < x->val)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if(y == NULL)
        T = z;

    else if(z->val < y->val)
        y->left = z;
    else
        y->right = z;

    z->left = NULL;
    z->right = NULL;
    z->color = RED;
    RB_Insert_Fixup(T, z);
}

