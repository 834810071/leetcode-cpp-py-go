#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0]) if rows else 0
        for i in range(rows // 2):
            for j in range(cols):
                matrix[i][j], matrix[rows - i -
                                     1][j] = matrix[rows - i -
                                                    1][j], matrix[i][j]

        for i in range(rows):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]


if __name__ == '__main__':
    sol = Solution()
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    sol.rotate(matrix)
    print(matrix)

    matrix = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    sol.rotate(matrix)
    print(matrix)

    matrix = [[1]]
    sol.rotate(matrix)
    print(matrix)

    matrix = [[1, 2], [3, 4]]
    sol.rotate(matrix)
    print(matrix)
