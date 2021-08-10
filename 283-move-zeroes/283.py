#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return
        size = len(nums)
        cur = 0
        for i in range(size):
            if nums[i] != 0:
                nums[cur] = nums[i]
                cur += 1
        
        for i in range(cur, size):
            nums[i] = 0

if __name__ == '__main__':
    sol = Solution()
    nums = [0,1,0,3,12]
    sol.moveZeroes(nums)
    print(nums)