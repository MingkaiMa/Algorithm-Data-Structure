
void Transplant(BST* T, BST* u, BST* v)
{
    if(u->parent == NULL)
        T = v;

    else if u ==u->parent->left
        u->parent->left = v;

    else
        u->parent->right = v;

    if(v != NULL)
        v->parent = u->parent;
}

void BST_Delete(BST* T, BST* z)
{
    if(z->left == NULL)
        Transplant(T, z, z->right);

    else if(z->right == NULL)
        Transplant(T, z, z->left);

    else
    {
        //y is the successor of z
        y = Minimum(z->right);

        if(y->parent != z)
        {
            Transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;

        }

        Transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
    }

}