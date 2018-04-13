#include <iostream>
using namespace std;

int getMin(int a, int b, int c)
{
    return min(a, b) > c ? c : min(a, b);
}


int getUglyNumberUpToN(int N)
{

    int *array = new int[N];

    array[0] = 1;

    int* n2 = array;
    int* n3 = array;
    int* n5 = array;

    int next = 1;

    while(next < N)
    {

        int minAmong235 = getMin(*n2 * 2, *n3 * 3, *n5 * 5);
        array[next] = minAmong235;


        while(*n2 * 2 <= array[next])
            n2++;

        while(*n3 * 3 <= array[next])
            n3++;

        while(*n5 * 5 <= array[next])
            n5++;


        next++;
    }

    for(int i = 0; i < N; i++)
        cout << array[i] << ", ";
    cout << endl;

    int res = array[N - 1];
    return res ;

}

int main()
{
    int N = 1500;
    cout << getUglyNumberUpToN(N) << endl;
}