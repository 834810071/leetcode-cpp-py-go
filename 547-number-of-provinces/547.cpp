#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        if (len == 0) return 0;
        int res = 0;
        vector<bool> vec = vector<bool>(len, true);
        queue<int> q;
        for (int i = 0; i < len; ++i) {
            if (vec[i]) {
                vec[i] = false;
                q.push(i);
                while (!q.empty()) {
                    int pop = q.front();
                    q.pop();
                    for (int j = 0; j < len; ++j) {
                        if (isConnected[pop][j] == 1 && vec[j]) {
                            vec[j] = false;
                            q.push(j);
                        }
                    }
                }
                ++res;
            }
        }
        return res;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<vector<int>> isConnected1 = {{1,1,0},{1,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected1) << endl;
    vector<vector<int>> isConnected2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << sol.findCircleNum(isConnected2) << endl;
    return 0;
}