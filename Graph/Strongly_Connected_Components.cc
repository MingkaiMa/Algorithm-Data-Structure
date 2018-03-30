
STRONGLY_CONNECTED_COMPONENT(G)
{
    call DFS(G) to compute finishing times u.f for each vertex u
    compute GT
    call DFS(GT), but in the main loop of DFS, consider the vertices in order of decreasing u.f
    output the vertices of each tree in the depth-first forest formed in line 3 as a separate strongly connected component
}