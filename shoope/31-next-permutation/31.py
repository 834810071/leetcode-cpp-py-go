#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys
from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while i < j and nums[i] >= nums[j]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        j, i = len(nums) - 1, i + 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1


if __name__ == '__main__':
    sol = Solution()
    nums = [1, 2, 3]
    sol.nextPermutation(nums)
    print(nums)
    nums = [3, 2, 1]
    sol.nextPermutation(nums)
    print(nums)
    nums = [1, 1, 5]
    sol.nextPermutation(nums)
    print(nums)
    nums = [1]
    sol.nextPermutation(nums)
    print(nums)
    nums = [1, 5, 1]
    sol.nextPermutation(nums)
    print(nums)
    nums = [5, 1, 1]
    sol.nextPermutation(nums)
    print(nums)
