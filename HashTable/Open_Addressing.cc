#include <iostream>


void Hash_Insert(T, k)
{
    i = 0;
    do
    {
        j = h(k, i);
        if T[j] == NULL
        {
            T[j] = k;
            return j;
        }
        else
            i += 1;
    }
    until(i == m);

    cout << "hash table overflow"
}

void Hash_Search(T, k)
{
    i = 0;
    do
    {
        j = h(k, i);
        if T[j] == k
            return j;

        i += 1;
    }until(T[j] == NULL || i == m)

    return NULL;
}