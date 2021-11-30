#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int size = nums.size();
        int cur = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] != 0) {
                nums[cur++] = nums[i]; 
            }
        }
        while (cur < size) {
            nums[cur++] = 0;
        }
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    for (auto a : nums) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}