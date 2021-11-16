#!/usr/bin/env python
# -*- coding:utf-8 -*-
from typing import Dict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic: Dict[str, int] = {}
        l, res = -1, 0
        for r in range(len(s)):
            if s[r] in dic:
                l = max(l, dic[s[r]])

            dic[s[r]] = r
            res = max(res, r - l)
        return res


if __name__ == '__main__':
    sol = Solution()
    print(sol.lengthOfLongestSubstring("abcabcbb"))
    print(sol.lengthOfLongestSubstring("bbbbb"))
    print(sol.lengthOfLongestSubstring("pwwkew"))
    print(sol.lengthOfLongestSubstring(" "))
