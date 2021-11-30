#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp: List[int] = [0 for i in range(len(cost) + 1)]
        for i in range(2, len(cost) + 1):
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1])

        return dp[-1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.minCostClimbingStairs([10, 15, 20]))
    print(sol.minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))
