#include <iostream>

// use chaining to deal with the collision
// O(1)
void Chained_Hash_Insert(T, x)
{
    insert x at the head of list T[h(x.key)];
}

void Chained_Hash_Search(T, k)
{
    search for an element with key k in list T[h(k)];
}

void Chained_Hash_Delete(T, x)
{
    delete x from the list T[h(x.key)];
}