#include <vector>

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
    void dp(vector<int> &nums, TreeNode *parent, int start, int end)
    {
        if (start >= end)
            return;

        int p = (start + end) / 2;
        TreeNode *currentNode = new TreeNode(nums[p]);

        if (parent->val < currentNode->val)
            parent->right = currentNode;
        else
            parent->left = currentNode;

        dp(nums, currentNode, start, p);
        dp(nums, currentNode, p + 1, end);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int p = nums.size() / 2;
        TreeNode *res = new TreeNode(nums[p]);

        dp(nums, res, 0, p);
        dp(nums, res, p+1,nums.size());
        return res;
    }
};