/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    res := math.MinInt32
    var dfs func(*TreeNode) int
    dfs = func(node *TreeNode) int {
        if node == nil {
            return 0
        }

        left := max(dfs(node.Left), 0)
        right := max(dfs(node.Right), 0)
        res = max(left + right + node.Val, res)
        return max(left, right) + node.Val
    }
    dfs(root)
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}