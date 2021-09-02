#!/usr/bin/env python
# -*- coding:utf-8 -*-

from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.judge(root.left, root.right)

    def judge(self, left: Optional[TreeNode],
              right: Optional[TreeNode]) -> bool:
        if not left and not right:
            return True
        if not left or not right:
            return False
        return left.val == right.val and \
            self.judge(left.right, right.left) and self.judge(left.left, right.right)


if __name__ == '__main__':
    sol = Solution()
    t1 = TreeNode(1)
    t2 = TreeNode(2)
    t3 = TreeNode(2)
    t4 = TreeNode(3)
    t5 = TreeNode(4)
    t6 = TreeNode(4)
    t7 = TreeNode(3)
    t1.left = t2
    t1.right = t3
    t2.left = t4
    t2.right = t5
    t3.left = t6
    t3.right = t7
    print(sol.isSymmetric(t1))

    t1 = TreeNode(1)
    t2 = TreeNode(2)
    t3 = TreeNode(2)
    t4 = TreeNode(3)
    t5 = TreeNode(3)
    t1.left = t2
    t1.right = t3
    t2.right = t4
    t3.right = t5
    print(sol.isSymmetric(t1))
