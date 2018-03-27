
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

void RB_Insert_Fixup(BST* T, BST* z)
{
    while(z->parent->color == RED)
    {

        if(z->parent == z->parent->parent->left)
        {

            BST* y = z->parent->parent->right;
            if(y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }

            else if(z == z->parent->right)
            {

                z = z->parent;
                leftRotate(T, z);
            }

            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            rightRotate(T, z->parent->parent);


        }
        else
            ;//same as then clause with "right" and "left" exchanged
    }
    T->color = BLACK;
}