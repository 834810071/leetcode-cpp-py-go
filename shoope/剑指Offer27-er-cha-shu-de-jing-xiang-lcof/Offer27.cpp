#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
    Definition for a binary tree node.
**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirrorTree(root->right);
        mirrorTree(root->left);
        return root;
    }
};

void print(TreeNode* t) {
    if (t == nullptr) return;
    queue<TreeNode*> q;
    q.push(t);
    int size = 0;
    cout << "[ ";
    while (!q.empty()) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
            cout << q.front()->val << ", ";
            TreeNode* tmp = q.front();
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
            q.pop();
        }
    }
    cout << "]" << endl;
}

int main(int argc, char** args) {
    TreeNode* t1 = new TreeNode(4);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(7);
    TreeNode* t4 = new TreeNode(1);
    TreeNode* t5 = new TreeNode(3);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t7 = new TreeNode(9);

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t4->left = t5;
    t3->left = t6;
    t3->right = t7;
    Solution s = Solution();
    s.mirrorTree(t1);
    print(t1);
    
    return 0;
}