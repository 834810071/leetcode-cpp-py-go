#!/usr/bin/env python
# -*- coding:utf-8 -*-
from typing import List, Optional


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums = sorted(nums)
        return max((nums[0] * nums[1] * nums[-1]),
                   (nums[-3] * nums[-2] * nums[-1]))


if __name__ == '__main__':
    sol = Solution()
    nums = [1, 2, 3]
    print(sol.maximumProduct(nums))
    nums = [1, 2, 3, 4]
    print(sol.maximumProduct(nums))
    nums = [-1, -2, -3]
    print(sol.maximumProduct(nums))