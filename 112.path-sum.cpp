/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool ok = false;
    void travsal(TreeNode *root, int sum, int target)
    {
        if (ok)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            if (sum + root->val == target)
            {
                ok = true;
            }
            return;
        }
        if (root->left)
        {
            travsal(root->left, sum + root->val, target);
        }
        if (root->right)
        {
            travsal(root->right, sum + root->val, target);
        }
    }
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
        {
            return false;
        }
        travsal(root, 0, sum);
        return ok;
    }
};
// @lc code=end
