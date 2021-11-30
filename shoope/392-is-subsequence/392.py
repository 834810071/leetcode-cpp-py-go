#!/usr/bin/env python
# -*- coding:utf-8 -*-


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        len1, len2 = len(s), len(t)
        i, j = 0, 0
        while (i < len1 and j < len2):
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == len1


if __name__ == '__main__':
    sol = Solution()
    print(sol.isSubsequence("abc", "ahbgdc"))
    print(sol.isSubsequence("axc", "ahbgdc"))
