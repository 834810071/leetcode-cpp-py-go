#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if len(s) <= 10:
            return []
        one, second = set(), set()
        one.add(s[:10])
        for i in range(1, len(s)-9):
            if s[i:i+10] in one:
                second.add(s[i:i+10])
            else:
                one.add(s[i:i+10])
        return list(second)


if __name__ == '__main__':
    sol = Solution()
    print(sol.findRepeatedDnaSequences('AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT'))
    print(sol.findRepeatedDnaSequences('AAAAAAAAAAAAA'))