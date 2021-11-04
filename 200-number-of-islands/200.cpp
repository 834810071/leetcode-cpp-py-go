#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int DIR = 4;
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    vector<vector<bool>> _visited;
    vector<vector<char>> _grid;
    int m, n;
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid.empty() ? 0 : grid[0].size();
        if (n == 0)
            return 0;
        _grid = grid;
        _visited.assign(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (_grid[i][j] == '1' && !_visited[i][j])
                {
                    dfs(i, j);
                    ++res;
                }
            }
        }
        return res;
    }

    bool valid(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(int x, int y)
    {
        if (!valid(x, y) || _grid[x][y] == '0' || _visited[x][y])
            return;

        _visited[x][y] = true;
        for (int i = 0; i < DIR; ++i)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];
            dfs(nx, ny);
        }
    }
};

int main(int argc, char **args)
{
    Solution sol = Solution();
    vector<vector<char>> grid_1 = {{'1', '1', '1', '1', '0'},
                                   {'1', '1', '0', '1', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '0', '0', '0'}};
    cout << sol.numIslands(grid_1) << endl;
    vector<vector<char>> grid_2 = {{'1', '1', '0', '0', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '1', '0', '0'},
                                   {'0', '0', '0', '1', '1'}};
    cout << sol.numIslands(grid_2) << endl;
    return 0;
}