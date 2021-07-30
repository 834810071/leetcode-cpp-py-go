#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys
from typing import List

class Solution:
    def getMaxMatrix(self, matrix: List[List[int]]) -> List[int]:
        ans = [0] * 4
        row = len(matrix)
        col = len(matrix[0])
        if row == 0 or col == 0:
            return []
        ans1, ans2 = 0, 0
        maxsum = -sys.maxsize - 1
        for i in range(row):
            arr = [0 for _ in range(col)]
            for j in range(i, row):
                sum1 = 0
                for n in range(col):
                    arr[n] += matrix[j][n]
                    if sum1 > 0:
                        sum1 += arr[n]
                    else:
                        sum1 = arr[n]
                        ans1, ans2 = i, n
                    if maxsum < sum1:
                        maxsum = sum1
                        ans[0] = ans1
                        ans[1] = ans2
                        ans[2] = j
                        ans[3] = n
        return ans

if __name__ == '__main__':
    sol = Solution()
    matrix = [[-1, -2, -9, 6], [8, -9, -3, -6], [2, 9, -7, -6]]
    print(sol.getMaxMatrix(matrix))

    matrix = [[9,-8,1,3,-2],[-3,7,6,-2,4],[6,-4,-4,8,-7]]
    print(sol.getMaxMatrix(matrix))