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
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root: Optional[TreeNode]):
            nonlocal count
            if root:
                dfs(root.right)
                count += root.val
                root.val = count
                dfs(root.left)

        count = 0
        dfs(root)
        return root


if __name__ == '__main__':
    print('I am lazy')
