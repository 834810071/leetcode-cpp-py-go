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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            res = q.front() -> val;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            if (q.empty()) return res;
        }
        return res;
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(1);
    TreeNode* t3 = new TreeNode(3);
    
    t1->left = t2;
    t1->right = t3;
    cout << sol.findBottomLeftValue(t1) << endl;

    t1 = new TreeNode(1);
    t2 = new TreeNode(2);
    t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t7 = new TreeNode(7);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->left = t5;
    t3->right = t6;
    t5->left = t7;
    cout << sol.findBottomLeftValue(t1) << endl;
    
    return 0;
}