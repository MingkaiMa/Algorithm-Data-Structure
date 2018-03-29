
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

B_TREE_INSERT_NONFULL(x, k)
{
    i = x.n;
    if x.leaf
        while i >= 1 && k < x.keyi
            x.key(i + 1) = x.keyi;
            i -= 1;

        x.key(i + 1) = k;
        x.n = x.n + 1;
        DISK_WRITE(x);

    else while i >= 1 && k < x.keyi
            i -= 1;

        i += 1;
        DISK_READ(x.ci);
        if x.ci.n == 2 * t - 1
            B_TREE_SPLIT_CHILD(x, i);
            if k > x.keyi
                i += 1
        B_TREE_INSERT_NONFULL(x.ci, k);

}