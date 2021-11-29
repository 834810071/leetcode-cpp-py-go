#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
        {
            return;
        }

        int l = 0, r = len - 1, cur = 0;

        while (cur <= r && l < r)
        {
            if (nums[cur] == 0)
            {
                swap(nums[cur], nums[l]);
                ++l;
                ++cur;
            }
            else if (nums[cur] == 2)
            {
                swap(nums[cur], nums[r]);
                --r;
            }
            else
            {
                ++cur;
            }
        }
    }
};

int main(int argc, char **args)
{
    Solution sol = Solution();
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    for (auto a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    nums = {2, 0, 1};
    sol.sortColors(nums);
    for (auto a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    nums = {0};
    sol.sortColors(nums);
    for (auto a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    nums = {1};
    sol.sortColors(nums);
    for (auto a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}