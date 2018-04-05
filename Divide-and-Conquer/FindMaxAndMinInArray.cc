#include <iostream>
#include <vector>

using namespace std;


vector<int> findMaxAndMin(int* arr, int b, int e)
{
    if(e - b <= 1)
    {
        vector<int> res(2);

        if(arr[e] < arr[b])
        {
            res[0] = arr[b];
            res[1] = arr[e];
            return res;
        }
        else
        {
            res[0] = arr[e];
            res[1] = arr[b];
            return res;
        }
    }

    vector<int> res1 = findMaxAndMin(arr, b, (b + e) >> 1);
    vector<int> res2 = findMaxAndMin(arr, ((b + e) >> 1) + 1, e);

    int max1 = res1[0];
    int min1 = res1[1];

    int max2 = res2[0];
    int min2 = res2[1];

    int max_ = max1 > max2 ? max1 : max2;
    int min_ = min1 < min2 ? min1 : min2;

    vector<int> res = {max_, min_};
    return res;
}

int main()
{
    int arr[6] = {5,6,8,3,7,9};
    vector<int> res = findMaxAndMin(arr, 0, 5);

    for(auto& i: res)
        cout << i << ", ";
    cout << endl;
}