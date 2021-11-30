#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = [False] * len(matrix)
        cols = [False] * len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if not matrix[i][j]:
                    rows[i] = cols[j] = True

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if rows[i] or cols[j]:
                    matrix[i][j] = 0


if __name__ == '__main__':
    sol = Solution()
    matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    sol.setZeroes(matrix)
    print(matrix)
    matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    sol.setZeroes(matrix)
    print(matrix)
