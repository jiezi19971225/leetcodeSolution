/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool solve(TreeNode *s, TreeNode *t)
    {
        if (ok)
        {
            return true;
        }
        if (!s && !t)
        {
            return true;
        }

        if ((s && !t) || (!s && t) || (s->val != t->val))
        {
            return false;
        }
        bool lok = solve(s->left, t->left);
        bool rok = solve(s->right, t->right);
        return lok && rok;
    }
    void travsal(TreeNode *s, TreeNode *t)
    {
        if (!s || ok)
        {
            return;
        }
        ok = solve(s, t);
        travsal(s->left, t);
        travsal(s->right, t);
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
        {
            return true;
        }
        travsal(s, t);
        return ok;
    }
};
// @lc code=end
