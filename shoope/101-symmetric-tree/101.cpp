#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return judge(root->left, root->right);
    }

    bool judge(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        return left->val == right->val && judge(left->right, right->left) && judge(left->left, right->right);
    }
};

int main(int argc, char** args) {
    Solution sol = Solution();
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(2);
    TreeNode* t4 = new TreeNode(3);
    TreeNode* t5 = new TreeNode(4);
    TreeNode* t6 = new TreeNode(4);
    TreeNode* t7 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    cout << sol.isSymmetric(t1) << endl;

    t1 = new TreeNode(1);
    t2 = new TreeNode(2);
    t3 = new TreeNode(2);
    t4 = new TreeNode(3);
    t5 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    t2->right = t4;
    t3->right = t5;
    cout << sol.isSymmetric(t1) << endl;
    
    return 0;
}