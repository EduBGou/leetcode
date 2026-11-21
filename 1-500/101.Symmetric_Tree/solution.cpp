
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
    void dp(TreeNode *p, TreeNode *q, bool &res)
    {
        if (p->val != q->val)
        {
            res = false;
            return;
        }

        if (p->left != nullptr && q->right != nullptr)
        {
            dp(p->left, q->right, res);
        }
        else if (p->left != q->right)
        {
            res = false;
            return;
        }

        if (res == false)
            return;

        if (p->right != nullptr && q->left != nullptr)
        {
            dp(p->right, q->left, res);
        }
        else if (p->right != q->left)
        {
            res = false;
            return;
        }
    }

    bool isSymmetric(TreeNode *root)
    {
        bool res = true;
        if (root->left != nullptr && root->right != nullptr)
        {
            dp(root->left, root->right, res);
        }
        else if (root->right != root->left)
        {
            res = false;
        }
        return res;
    }
};