#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

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
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = depth(root->left);
        if (left == -1)
            return -1;

        int right = depth(root->right);
        if (right == -1)
            return -1;

        if (abs(right - left) > 1)
            return -1;

        else
            return 1 + max(right, left);
    }
};
