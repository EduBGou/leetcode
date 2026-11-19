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

#include <vector>

using namespace std;

class Solution
{
public:
    void dp(vector<int> &res, TreeNode &current)
    {
        if (current.left == nullptr && current.right == nullptr)
        {
            res.push_back(current.val);
            return;
        }

        if (current.left != nullptr)
        {
            dp(res, *current.left);
        }

        res.push_back(current.val);

        if (current.right != nullptr)
        {
            dp(res, *current.right);
        }
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res = {};
        if (root == nullptr)
            return res;

        dp(res, *root);
        return res;
    }
};