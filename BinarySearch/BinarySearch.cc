#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& nums, int k){

	int left = 0, right = nums.size() - 1;

	while(left <= right){
		int mid = left + (right - left) / 2;

		cout << "left is: " << left << " right is: " << right << endl;
		if(nums[mid] == k)
			return mid;

		if(nums[mid] > k)
			right = mid - 1;

		else
			left = mid + 1;
	}

	return -1;
}

int main(){

	vector<int> nums = {1,  3, 5, 7};
	cout << BinarySearch(nums, 2) << endl;
}