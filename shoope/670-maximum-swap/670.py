#!/usr/bin/env python
# -*- coding:utf-8 -*-


class Solution:
    def maximumSwap(self, num: int) -> int:
        maxnum, maxloc, maxchange = -1, -1, 0
        for i, n in enumerate(str(num)[::-1]):
            tmp = int(n)
            if maxnum < tmp:
                maxnum = tmp
                maxloc = i
            else:
                change = (maxnum - tmp) * 10**i + (tmp - maxnum) * 10**maxloc
                maxchange = max(maxchange, change)

        return num + maxchange


if __name__ == '__main__':
    sol = Solution()
    print(sol.maximumSwap(2736))
    print(sol.maximumSwap(9973))
    print(sol.maximumSwap(9278))
