#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List

class Solution:
    def compressString(self, S: str) -> str:
        if len(S) == 0:
            return ''
        res = ''
        pre, count = S[0], 1
        for i in range(1, len(S)):
            if S[i] == pre:
                count += 1
            else:
                res += (pre + str(count))
                pre, count = S[i], 1
        
        res += (pre + str(count))

        return S if len(res) >= len(S) else res


if __name__ == '__main__':
    sol = Solution()
    print(sol.compressString('aabcccccaaa'))
    print(sol.compressString('abbccd'))