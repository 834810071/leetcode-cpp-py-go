#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp = vector<int>(size+1, 0);
        for (int i = 2; i <= size; ++i) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[size];
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<int> cost1 = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost1) << endl;
    
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << sol.minCostClimbingStairs(cost2) << endl;

    return 0;
}