/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *cur = root;
        while (1)
        {

            if (p->val <= cur->val && q->val >= root->val)
            {
                return cur;
            }
            else if (p->val < cur->val && q->val < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        return cur;
    }
};
// @lc code=end
