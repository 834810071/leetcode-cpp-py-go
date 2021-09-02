#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        if numRows == 1: return res
        res.append([1, 1])
        if numRows == 2: return res
        for i in range(2, numRows):
            size = len(res[-1])
            res.append([1 for j in range(size + 1)])
            for j in range(1, size):
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1]
        return res


if __name__ == '__main__':
    sol = Solution()
    print(sol.generate(5))
    print(sol.generate(1))
