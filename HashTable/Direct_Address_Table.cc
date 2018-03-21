#include <iostream>

int Direct_Address_Search(T, k)
{
    return T[k];
}

void Direct_Address_Insert(T, x)
{
    T[x.key] = x;
}

void Direct_Address_Delete(T, x)
{
    T[x.key] = NULL;
}