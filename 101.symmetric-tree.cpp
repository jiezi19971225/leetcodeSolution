/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool ok = true;
    void solve(TreeNode *left, TreeNode *right)
    {
        if (!ok)
        {
            return;
        }

        if (!left && !right)
        {
            return;
        }
        if ((left && !right) || (!left && right) || left->val != right->val)
        {
            ok = false;
            return;
        }
        solve(left->left, right->right);
        solve(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        solve(root->left, root->right);
        return ok;
    }
};
// @lc code=end
