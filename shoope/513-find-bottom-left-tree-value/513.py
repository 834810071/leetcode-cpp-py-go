#!/usr/bin/env python
# -*- coding:utf-8 -*-

from collections import deque
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> Optional[int]:
        dq: deque = deque([root])
        while dq:
            tmp = dq[0].val
            for i in range(len(dq)):
                cur = dq.popleft()
                if cur.left:
                    dq.append(cur.left)
                if cur.right:
                    dq.append(cur.right)
            if not dq:
                return tmp


if __name__ == '__main__':
    sol = Solution()
    t1 = TreeNode(2)
    t2 = TreeNode(1)
    t3 = TreeNode(3)
    t1.left = t2
    t1.right = t3
    print(sol.findBottomLeftValue(t1))

    t1 = TreeNode(1)
    t2 = TreeNode(2)
    t3 = TreeNode(3)
    t4 = TreeNode(4)
    t5 = TreeNode(5)
    t6 = TreeNode(6)
    t7 = TreeNode(7)
    t1.left = t2
    t1.right = t3
    t2.left = t4
    t3.left = t5
    t3.right = t6
    t5.left = t7
    print(sol.findBottomLeftValue(t1))
