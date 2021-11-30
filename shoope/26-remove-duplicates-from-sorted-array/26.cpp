#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int len = nums.size();
        if (len == 0) return 0;
        for (int j = 0; j < len; ++j) {
            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<int> nums1 = {1,1,2};
    int res1 = sol.removeDuplicates(nums1);
    cout << res1 << endl;

    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};
    int res2 = sol.removeDuplicates(nums2);
    cout << res2 << endl;
    return 0;
}