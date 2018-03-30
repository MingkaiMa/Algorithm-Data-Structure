
Topological_Sort(G)
{
    call DFS(G) to compute finishing times v.f for each vertex
    as each vertex is finished, insert it onto the front of a linked list
    return the linked list of vertices
}