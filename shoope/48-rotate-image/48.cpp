#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows == 0 ? 0 : matrix[0].size();
        if (cols == 0) {
            return;
        }

        for (int i = 0; i < rows/2; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] += matrix[rows-i-1][j];
                matrix[rows-i-1][j] = matrix[i][j] - matrix[rows-1-i][j];
                matrix[i][j] -= matrix[rows-i-1][j];
            }
        }

        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < i; ++j) {
                matrix[i][j] += matrix[j][i];
                matrix[j][i] = matrix[i][j] - matrix[j][i];
                matrix[i][j] -= matrix[j][i];
            }
        }
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);
    for (auto a : matrix) {
        for  (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(matrix);
    for (auto a : matrix) {
        for  (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{1}};
    sol.rotate(matrix);
    for (auto a : matrix) {
        for  (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;

    matrix = {{1,2},{3,4}};
    sol.rotate(matrix);
    for (auto a : matrix) {
        for  (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}