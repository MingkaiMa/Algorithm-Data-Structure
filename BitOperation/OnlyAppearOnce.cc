#include <iostream>
#include <vector>

using namespace std;

int appearOnlyOnce(vector<int>& nums){

	if(nums.size() <= 0)
		return -1;
	if(nums.size() == 1)
		return nums[0];

	int temp = nums[0];

	for(int i = 1; i < nums.size(); i++){
		temp = temp ^ nums[i];
	}
	return temp;
}

int main(){
	vector<int> nums = {2, 4, 3, 6, 6, 4, 3, 2, 5, 5,8};
	cout << appearOnlyOnce(nums) << endl;
}