#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys
from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        vis: List[bool] = [False] * len(nums)
        res: List[List[int]] = []
        perm: List[int] = []
        nums.sort()
        self.dfs(nums, vis, res, 0, perm)
        return res

    def dfs(self, nums: List[int], vis: List[bool], res: List[List[int]],
            cur: int, perm: List[int]):
        if cur == len(nums):
            res.append(perm.copy())
            return

        for i in range(len(nums)):
            if vis[i] or (i > 0 and nums[i] == nums[i - 1] and not vis[i - 1]):
                continue

            vis[i] = True
            perm.append(nums[i])
            self.dfs(nums, vis, res, cur + 1, perm)
            perm.pop()
            vis[i] = False


if __name__ == '__main__':
    sol = Solution()
    nums = [1, 1, 2]
    print(sol.permuteUnique(nums))
    nums = [1, 2, 3]
    print(sol.permuteUnique(nums))
