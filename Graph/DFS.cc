
DFS(G)
{
    for each vertex u in G.V
        u.color = WHITE;
        u.pi = NULL;

    time = 0;

    for each vertex u in G.V
        if u.color == WHITE
            DFS_VISIT(G, u);
}

DFS_VISIT(G, u)
{
    time = time + 1;
    u.d = time;
    u.color = GRAY;
    for each v in G.Adj[u]
        if v.color == WHITE
            v.pi = u
            DFS_VISIT(G, v)

    u.color = BLACK;
    time = time + 1;
    u.f = time;
}