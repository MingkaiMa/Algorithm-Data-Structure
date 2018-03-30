
PRINT_PATH(G, s, v)
{
    if v == s
        print s;
    else if v.pi = NULL
        print "No path from s to v exists";

    else
        PRINT_PATH(G, s, v.pi);
        print(v);
}