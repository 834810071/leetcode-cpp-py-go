#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import List

class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        def recr(l: int, r: int) -> bool:
            if l >= r: return True
            i = l
            while postorder[i] < postorder[r]: i += 1
            mid = i
            while i < r and postorder[i] > postorder[r]: i += 1
            return i == r and recr(l, mid-1) and recr(mid, r-1)
        
        return recr(0, len(postorder)-1)


if __name__ == '__main__':
    sol = Solution()
    print(sol.verifyPostorder([1,6,3,2,5]))
    print(sol.verifyPostorder([1,3,2,6,5]))