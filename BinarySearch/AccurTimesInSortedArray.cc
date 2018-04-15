#include <iostream>
#include <vector>

using namespace std;

int getFirstAccur(vector<int>& nums, int k)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {

        int mid = (left + right) >> 1;

        if(nums[mid] == k)
        {
            if(mid == 0 || nums[mid - 1] != k)
            {
                return mid;
            }
            else
                right = mid - 1;
        }
        else if(nums[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int getLastAccur(vector<int>& nums, int k)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) >> 1;

        if(nums[mid] == k)
        {
            if(mid == nums.size() - 1 || nums[mid + 1] != k)
                return mid;
            else
                left = mid + 1;

        }
        else if(nums[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}


int main()
{
    vector<int> L = {1,2,3,3,3,3,4,5,6};
    int n1 = getFirstAccur(L, 3);
    int n2 = getLastAccur(L, 3);

    if(n1 == -1 || n2 == -1)
        cout << 0 << endl;

    else
        cout << n2 - n1 + 1 << endl;
}
