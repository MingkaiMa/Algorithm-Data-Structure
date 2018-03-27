
void RB_Transplant(BST* T, BST* u, BST* v)
{
    if(u->parent == NULL)
        T = v;

    else if(u == u->parent->left)
        u->parent->left = v;

    else
        u->parent->right = v;
    v->parent = u->parent;
}


void RB_Delete(BST* T, BST* z)
{
    BST* y = z;
    y_original_color = y->color;

    if(z->left == NULL)
    {
        BST* x = z->right;
        RB_Transplant(T, z, z->right);
    }

    else if(z->right == NULL)
    {
        BST* x = z->left;
        RB_Transplant(T, z, z->left);
    }

    else
    {
        y = TREE_Minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == z)
            x->parent = y;

        else
        {
            RB_Transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        RB_Transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if(y_original_color == BLACK)
    {
        RB_Delete_Fixup(T, x);
    }
}

void RB_Delete_Fixup(T, x)
{
    while(x != T && x->color == BLACK)
    {
        if(x == x->parent->left)
        {
            BST* w = x->parent->right;
            if(w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(T, x->parent);
                w = x->parent->right;
            }

            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }

            else if(w->right->color == BLACK)
            {
                w->left->color = BLACK;
                w->color = RED;
                rightRotate(T, w);
                w = x->parent->color;
            }

            w->color = x->parent->color;
            x->parent->color = BLACK;
            w->right->color = BLACK;
            leftRotate(T, x->parent);
            x = T;
        }
        else
            ; // same as then clause with "right" and "left" exchanged

    }
    x->color = BLACK;
}