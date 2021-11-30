#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def valid(x: int, y: int):
            return x >= 0 and x < len(grid) and y >= 0 and y < len(grid[0])

        visited: List[List[bool]] = [[False for i in range(len(grid[0]))]
                                     for j in range(len(grid))]

        def dfs(x: int, y: int):
            if not valid(x, y) or visited[x][y] or grid[x][y] == '0':
                return

            visited[x][y] = True
            for (a, b) in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                nx, ny = x + a, y + b
                dfs(nx, ny)

        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1' and not visited[i][j]:
                    res += 1
                    dfs(i, j)

        return res


if __name__ == '__main__':
    sol = Solution()
    grid_val = [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"],
                ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]
    print(sol.numIslands(grid_val))
    grid_val = [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"],
                ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]
    print(sol.numIslands(grid_val))
