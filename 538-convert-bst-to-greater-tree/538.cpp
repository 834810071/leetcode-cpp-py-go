#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root != nullptr)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};
int main(int argc, char **args)
{
    cout << "I am lazy" << endl;
    return 0;
}