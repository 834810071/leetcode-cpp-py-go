/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_sum = max(dfs(root->left), 0);
        int right_sum = max(dfs(root->right), 0);

        res = max(res, left_sum + right_sum + root->val);

        return max(left_sum, right_sum) + root->val;
    }
};