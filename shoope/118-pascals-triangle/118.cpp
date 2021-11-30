#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr = {{1}};
        if (numRows == 1) return arr;
        arr.push_back({1, 1});
        if (numRows == 2) return arr;
        for (int i = 2; i < numRows; ++i) {
            int len = arr[i-1].size();
            arr.push_back(vector<int>(len+1, 1));
            for (int j = 1; j < len; ++j) {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
        return arr;
    }
};

int main(int argc, char** args) {
    Solution s = Solution();
    vector<vector<int>> res = s.generate(5);
    for (auto a : res) {
        cout << "[ ";
        for (auto b : a) {
            cout << b << ", ";
        }
        cout << " ], ";
    }
    cout << endl;

    res = s.generate(1);
    for (auto a : res) {
        cout << "[ ";
        for (auto b : a) {
            cout << b << ", ";
        }
        cout << " ], ";
    }
    cout << endl;
    return 0;
}