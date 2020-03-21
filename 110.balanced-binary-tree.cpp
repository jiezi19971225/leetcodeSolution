/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

    int solve(TreeNode *root, int depth)
    {
        if (!ok)
        {
            return;
        }
        int lh = root->left ? solve(root->left, depth + 1) : depth;
        int rh = root->right ? solve(root->right, depth + 1) : depth;
        if (abs(lh - rh) > 1)
        {
            ok = false;
        }
        return max(lh, rh);
    }

    bool isBalanced(TreeNode *root)
    {
        solve(root, 0);
        return ok;
    }
};
// @lc code=end
