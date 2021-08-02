#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for j in range(len(nums)):
            if nums[i] != nums[j]:
                i += 1
                nums[i] = nums[j]
        return i + 1

if __name__ == '__main__':
    sol = Solution()
    nums = [1,1,2]
    print(sol.removeDuplicates(nums))

    nums = [0,0,1,1,1,2,2,3,3,4]
    print(sol.removeDuplicates(nums))