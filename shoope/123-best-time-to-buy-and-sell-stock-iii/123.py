#!/usr/bin/env python
# -*- coding:utf-8 -*-
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sell1 = sell2 = 0
        buy1 = buy2 = -prices[0]
        for i in range(1, len(prices)):
            buy1 = max(buy1, -prices[i])
            sell1 = max(sell1, prices[i] + buy1)
            buy2 = max(buy2, sell1 - prices[i])
            sell2 = max(sell2, prices[i] + buy2)

        return sell2


if __name__ == '__main__':
    sol = Solution()
    prices = [3, 3, 5, 0, 0, 3, 1, 4]
    print(sol.maxProfit(prices))
    prices = [1, 2, 3, 4, 5]
    print(sol.maxProfit(prices))
    prices = [7, 6, 4, 3, 1]
    print(sol.maxProfit(prices))
    prices = [1]
    print(sol.maxProfit(prices))
