#!/usr/bin/env python
# -*- coding:utf-8 -*-

import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        q = collections.deque()
        q.append(root)
        flag = False
        while q:
            size = len(q)
            for i in range(size):
                tmp = q.popleft()
                if tmp:
                    if flag:
                        return False
                    q.append(tmp.left)
                    q.append(tmp.right)
                else:
                    flag = True
        return True


if __name__ == '__main__':
    sol = Solution()
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
    t2.right = t5
    t3.right = t7
    print(sol.isCompleteTree(t1))
    t3.left = t6
    t3.right = None
    print(sol.isCompleteTree(t1))
