#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        bool reversed = false;
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            vector<int> tmpVec;
            for (int i = 0; i < len; ++i) {
                TreeNode *tmpNode = q.front();
                tmpVec.push_back(tmpNode->val);
                if (tmpNode->left) q.push(tmpNode->left);
                if (tmpNode->right) q.push(tmpNode->right);
                q.pop();
            }
            if (reversed) {
                reverse(tmpVec.begin(), tmpVec.end());
            }
            res.push_back(tmpVec);
            reversed = !reversed;
        }
        return res;
    }
};