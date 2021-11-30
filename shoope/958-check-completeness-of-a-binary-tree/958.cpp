#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q = queue<TreeNode*>();
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp == nullptr) {
                    flag = true;
                }
                else {
                    if (flag) return false;
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
        }
        return true;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t7 = new TreeNode(7);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    cout << sol.isCompleteTree(t1) << endl;

    t3->left = nullptr;
    t3->right = t7;
    cout << sol.isCompleteTree(t1) << endl;

    return 0;
}