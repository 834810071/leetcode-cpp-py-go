#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, pre = 0;
        unordered_map<int, int> mp{{0,1}};
        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            int diff = pre - k;
            if (mp.count(diff)) {
                count += mp[diff];
            }
            ++mp[pre];
        }
        return count;
    }
};

int main() {
	vector<int> vec = {1, 1, 1};
	Solution sol;
	cout << sol.subarraySum(vec, 2) << endl;
	vec = {1, 2, 3};
	cout << sol.subarraySum(vec, 3) << endl;
}