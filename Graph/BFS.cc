
BFS(G, s)
{
    for each vertex u in G.V - {s}
        u.color = WHITE;
        u.d = INIT_MAX;
        u.pi = NULL;


    s.color = GRAY;
    s.d = 0;
    s.pi = NULL;
    Queue Q;

    Q.push(s);
    while(!Q.empty())
    {
        u = Q.pop();
        for each v in G.Adj[u]
            if v.color == WHITE
                v.color = GRAY;
                v.d = u.d + 1;
                v.pi = u;
                Q.push(v);

        u.color = BLACK;
    }
}