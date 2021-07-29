#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List
from collections import deque

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        size = len(isConnected)
        arr = [True] * size
        dq = deque()
        res = 0
        for i in range(size):
            if arr[i]:
                arr[i] = False
                dq.append(i)
                while dq:
                    left = dq.popleft()
                    for j in range(0, size):
                        if isConnected[left][j] and arr[j]:
                            arr[j] = False
                            dq.append(j)
                res += 1
        return res

if __name__ == '__main__':
    sol = Solution()
    isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    print(sol.findCircleNum(isConnected))
    isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    print(sol.findCircleNum(isConnected))