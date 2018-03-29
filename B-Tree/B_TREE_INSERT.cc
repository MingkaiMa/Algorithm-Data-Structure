
B_TREE_INSERT(T, k)
{
    r = T.root;

    if r.n == 2 * t - 1
        s = ALLOCATE_NODE();
        T.root = s;
        s.leaf = false;
        s.n = 0;
        s.c1 = r;
        B_TREE_SPLIT_CHILD(s, 1);
        B_TREE_INSERT_NONFULL(s, k);
    else
        B_TREE_INSERT_NONFULL(r, k);
}