#!/usr/bin/env python
# -*- coding:utf-8 -*-
from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return
        r, b, cur = 0, len(nums) - 1, 0
        while cur <= b and r < b:
            if nums[cur] == 0:
                nums[cur], nums[r] = nums[r], nums[cur]
                cur += 1
                r += 1
            elif nums[cur] == 2:
                nums[cur], nums[b] = nums[b], nums[cur]
                b -= 1
            else:
                cur += 1


if __name__ == '__main__':
    sol = Solution()
    nums = [2, 0, 2, 1, 1, 0]
    sol.sortColors(nums)
    print(nums)
    nums = [2, 0, 1]
    sol.sortColors(nums)
    print(nums)
    nums = [0]
    sol.sortColors(nums)
    print(nums)
    nums = [1]
    sol.sortColors(nums)
    print(nums)
