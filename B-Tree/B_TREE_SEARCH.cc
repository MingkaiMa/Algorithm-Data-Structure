

B_TREE_SEARCH(x, k)
{
    i = 1;
    while(i < x.n && k > x.keyi)
        i += 1;

    if(i <= x.n && k == x.keyi)
        return (x, i);

    else if(x.leaf)
        return nullptr;

    else
    {
        DISK_READ(x, ci);
        return B_TREE_SEARCH(x.ci, k);
    }
}