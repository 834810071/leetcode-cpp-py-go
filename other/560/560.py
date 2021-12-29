# /usr/bin/python
# -*- coding:utf-8 -*-

from typing import List, Dict


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        pre, count = 0, 0
        mp: Dict[int, int] = {0: 1}
        for num in nums:
            pre += num
            diff = pre - k
            if diff in mp:
                count += mp[diff]
            mp[pre] = mp.get(pre, 0) + 1

        return count


if __name__ == '__main__':
    nums: List[int] = [1, 1, 1]
    sol = Solution()
    print(sol.subarraySum(nums, 2))
    nums = [1, 2, 3]
    print(sol.subarraySum(nums, 3))
