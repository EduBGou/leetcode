#include <vector>
#include <iostream>

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
    void dp(bool &res, TreeNode &currentP, TreeNode &currentQ)
    {
        auto l = currentP.left == nullptr && currentQ.left != nullptr || currentP.left != nullptr && currentQ.left == nullptr;
        auto r = currentP.right == nullptr && currentQ.right != nullptr || currentP.right != nullptr && currentQ.right == nullptr;

        if (currentP.val != currentQ.val || l || r)
        {
            res = false;
            return;
        }

        if (currentP.left != nullptr)
        {
            dp(res, *currentP.left, *currentQ.left);
        }

        if (currentP.right != nullptr)
        {
            dp(res, *currentP.right, *currentQ.right);
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        bool res = true;
        dp(res, *p, *q);
        return res;
    }
};

int main(){}