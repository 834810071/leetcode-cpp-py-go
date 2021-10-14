#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<bool> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vis.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, res, 0, perm);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, int cur, vector<int>& perm) {
        if (cur == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])) {
                continue;
            }
            vis[i] = true;
            perm.push_back(nums[i]);
            dfs(nums, res, cur + 1, perm);
            perm.pop_back();
            vis[i] = false;
        }
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<vector<int>> res;
	vector<int> nums1 = {1, 1, 2};
	res = sol.permuteUnique(nums1);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[0].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	vector<int> nums2 = {1, 2, 3};
	res = sol.permuteUnique(nums2);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[0].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
    
    return 0;
}