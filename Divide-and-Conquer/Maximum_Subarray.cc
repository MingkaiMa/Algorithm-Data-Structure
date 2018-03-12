#include <iostream>

using namespace std;

void FIND_MAX_CROSSING_SUBARRAY(int* A, int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;

    int right_sum = INI_MAX;

    int max_left = -1;
    int max_right = -1

    for(int i = mid; i >= low; i--)
    {
        sum += A[i];
        if(left_sum < sum)
        {
            left_sum = sum;
            max_left = i;
        }

    }

    sum = 0;
    for(int i = mid + 1; i <= high; i++)
    {
        sum += A[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    return (max_left, max_right, left_sum + right_sum);
}

void FIND_MAX_SUBARRAY(int* A, int low, int high)
{
    if(high == low)  //base case: only one element
    {
        return (low, high, A[low]);
    }

    else
    {
        int mid = (low + high) >> 1;

        (left_low, left_high, left_sum) = FIND_MAX_SUBARRAY(A, low, mid);

        (right_low, right_high, right_sum) = FIND_MAX_SUBARRAY(A, mid + 1, high);

        (cross_low, cross_high, cross_sum) = FIND_MAX_SUBARRAY(A, low, mid, high);

        if(left_sum >= right_sum && left_sum >= cross_sum)
            return (left_low, left_high, left_sum);

        if(right_sum >= left_sum && right_sum >= cross_sum)
            return (right_low, right_high, right_sum);

        else
            return (cross_low, cross_high, cross_sum);
    }
}