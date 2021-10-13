#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int x = matrix.size();
        int y = x != 0 ? matrix[0].size() : 0;
        if (y == 0) return;
        vector<bool> rows = vector<bool>(x, false);
        vector<bool> cols = vector<bool>(y, false);

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<vector<int>> matrix1 = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(matrix1);
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[0].size(); ++j) {
            cout << matrix1[i][j] << " "; 
        }
        cout << endl;
    }
    vector<vector<int>> matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(matrix2);
    for (int i = 0; i < matrix2.size(); ++i) {
        for (int j = 0; j < matrix2[0].size(); ++j) {
            cout << matrix2[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}