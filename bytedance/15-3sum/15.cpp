#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen < 3) return vector<vector<int>>{};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < numsLen-2; ++first) {
            if (first > 0 && nums[first] == nums[first-1]) continue;
            int target = -nums[first];
            int third = numsLen - 1;
            int second = first + 1;
            for (; second < numsLen-1; ++second) {
                if (second > first + 1 && nums[second] == nums[second-1]) continue;
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }

                if (second != third && nums[second] + nums[third] == target) {
                    res.push_back(vector<int>{nums[first], nums[second], nums[third]});
                }
            }
        }
        return res;
    }
};

void print(vector<vector<int>>& res) {
    for (auto & vec: res) {
        for (auto & v: vec) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution s = Solution();
    vector<vector<int>> res;
    vector<int> vec;
    vec = vector<int>{-1,0,1,2,-1,-4};
    res = s.threeSum(vec);
    print(res);

    vec = vector<int>{1,2,-2,-1};
    res = s.threeSum(vec);
    print(res);

    vec = vector<int>{0,0,0};
    res = s.threeSum(vec);
    print(res);

    vec = vector<int>{0,1,1};
    res = s.threeSum(vec);
    print(res);
    return 0;
}