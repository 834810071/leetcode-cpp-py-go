#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int preSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * preSum + nums[i] == sum) {
                return i;
            }
            preSum += nums[i];
        }
        return -1;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {1, 7, 3, 6, 5, 6};
	cout << sol.pivotIndex(nums) << endl;
	nums = {1, 2, 3};
	cout << sol.pivotIndex(nums) << endl;
	nums = {2, 1, -1};
	cout << sol.pivotIndex(nums) << endl;
	return 0;
}