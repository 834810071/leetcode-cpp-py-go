#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = row == 0 ? 0 : matrix[0].size();
        if (col == 0) return vector<int>();
        int ans1 = 0, ans2 = 0;
        vector<int> res(4, 0);
        int max = INT_MIN;
        for (int i = 0; i < row; ++i) {
            vector<int> dp(col, 0);
            for (int j = i; j < row; ++j) {
                int sum = 0;
                for (int n = 0; n < col; ++n) {
                    dp[n] += matrix[j][n];
                    if (sum > 0) {
                        sum += dp[n];
                    }
                    else {
                        sum = dp[n];
                        ans1 = i;
                        ans2 = n;
                    }
                    if (sum > max) {
                        max = sum;
                        res[0] = ans1;
                        res[1] = ans2;
                        res[2] = j;
                        res[3] = n; 
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<vector<int>> matrix1 = {{-1, -2, -9, 6}, {8, -9, -3, -6}, {2, 9, -7, -6}};
    vector<int> res1 = sol.getMaxMatrix(matrix1);
    for (auto& a : res1) {
        cout << a << " ";
    }
    cout << endl;

    vector<vector<int>> matrix2 = {{9,-8,1,3,-2}, {-3,7,6,-2,4}, {6,-4,-4,8,-7}};
    vector<int> res2 = sol.getMaxMatrix(matrix2);
    for (auto& a : res2) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}