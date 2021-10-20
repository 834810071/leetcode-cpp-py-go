#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) {
            --i;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (i < j && nums[i] >= nums[j]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
	vector<int> nums = {1,2,3};
	sol.nextPermutation(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;

    nums = {3,2,1};
	sol.nextPermutation(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;

	nums = {1,1,5};
	sol.nextPermutation(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;
    
    nums = {1};
	sol.nextPermutation(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;

    nums = {1,5,1};
	sol.nextPermutation(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;

    nums = {5,1,1};
	sol.nextPermutation(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}