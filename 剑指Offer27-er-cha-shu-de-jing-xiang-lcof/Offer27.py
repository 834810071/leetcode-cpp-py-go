#!/usr/bin/env python
# -*- coding:utf-8 -*-
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        root.left, root.right = root.right, root.left
        self.mirrorTree(root.left)
        self.mirrorTree(root.right)
        return root

def myprint(t: TreeNode) -> None:
    if not t:
        return None
    q:deque = deque()
    q.append(t)
    print('[', end='')
    while q:
        size = len(q)
        for i in range(size):
            tmp = q.popleft()
            print(tmp.val, end=', ')
            if tmp.left:
                q.append(tmp.left)
            if tmp.right:
                q.append(tmp.right)
    print(']')
if __name__ == '__main__':
    sol = Solution()
    t1 = TreeNode(4)
    t2 = TreeNode(2)
    t3 = TreeNode(7)
    t4 = TreeNode(1)
    t5 = TreeNode(3)
    t6 = TreeNode(6)
    t7 = TreeNode(9)
    t1.left = t2
    t1.right = t3
    t2.left = t4
    t2.right = t5
    t3.left = t6
    t3.right = t7
    sol.mirrorTree(t1)
    myprint(t1)