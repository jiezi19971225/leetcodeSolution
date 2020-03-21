/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    void solve(TreeNode *root)
    {
        swap(root->left, root->right);
        if (root->left)
        {
            solve(root->left);
        }
        if (root->right)
        {
            solve(root->right);
        }
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return NULL;
        }
        solve(root);
        return root;
    }
};
// @lc code=end
