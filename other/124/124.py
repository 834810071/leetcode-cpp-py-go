# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float("-inf")
        def dfs(root: Optional[TreeNode]):
            if not root: return 0
            
            left = max(0, dfs(root.left))
            right = max(0, dfs(root.right))

            self.res = max(self.res, left + right + root.val)

            return max(left, right) + root.val
        dfs(root)
        return self.res