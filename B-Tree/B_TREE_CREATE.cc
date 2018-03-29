
B_TREE_CREATE(T)
{
    x = ALLOCATE_NODE();
    x.leaf = true;
    x.n = 0;
    DISK_WRITE(x);
    T.root = x;
}