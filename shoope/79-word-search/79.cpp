#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        if (len == 0) return true;
        int rows = board.size();
        int cols = rows == 0 ? 0 : board[0].size();
        if (cols == 0) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool res = false;
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                if (board[i][j] == word[0]) {
                    res = dfs(board, i, j, visited, word, 0, rows, cols);
                }
                if (res) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited, string& word, int index, int rows, int cols) {
        if (word.size() == index) return true;
        if (x < 0 || y < 0 || x == rows || y == cols || visited[x][y] || board[x][y] != word[index]) return false;
        visited[x][y] = true;
        int res = dfs(board, x+1, y, visited, word, index+1, rows, cols) ||
            dfs(board, x-1, y, visited, word, index+1, rows, cols) ||
            dfs(board, x, y+1, visited, word, index+1, rows, cols) ||
            dfs(board, x, y-1, visited, word, index+1, rows, cols);
        visited[x][y] = false;
        return res;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << sol.exist(board, word) << endl;

    word = "SEE";
    cout << sol.exist(board, word) << endl;

    word = "ABCB";
    cout << sol.exist(board, word) << endl;
    return 0;
}