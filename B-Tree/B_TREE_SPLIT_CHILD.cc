
B_TREE_SPLIT_CHILD(x, i)
{
    z = ALLOCATE_NODE();
    y = x.ci;
    z.leaf = y.leaf;
    z.n = t - 1;
    for(int j = 1 j <= t - 1; j++)
        z.keyj = y.key(j + t);

    if not y.leaf
        for j = 1 to t
            z.cj = y.c(j + t);

    y.n = t - 1;
    for j = x.n + 1 downto i + 1
        x.c(j + 1) = x.cj;

    x.c(i + 1) = z;

    for j = x.n downto i
        k.key(j + 1) = x.keyj;

    x.keyi = y.keyt;
    x.n = x.n + 1;

    DISK_WRITE(y);
    DISK_WRITE(z);
    DISK_WRITE(x);
}