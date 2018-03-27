
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