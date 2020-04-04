/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int solve(TreeNode *root, int &res)
    {
        if (!root)
        {
            return 0;
        }
        int lmax = solve(root->left, res);
        if (lmax < 0)
        {
            lmax = 0;
        }
        int rmax = solve(root->right, res);
        if (rmax < 0)
        {
            rmax = 0;
        }
        res = max(res, root->val + lmax + rmax);
        return root->val + max(lmax, rmax);
    }
    int maxPathSum(TreeNode *root)
    {
        int res = -(1 << 30);
        solve(root, res);
        return res;
    }
};
// @lc code=end
