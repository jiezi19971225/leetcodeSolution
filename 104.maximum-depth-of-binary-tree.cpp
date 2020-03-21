/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
struct wrap
{
    TreeNode *node;
    int depth;
    wrap(TreeNode *node, int depth) : node(node), depth(depth){};
};
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int res = 0;
        queue<wrap *> q;
        q.push(new wrap(root, 1));
        while (!q.empty())
        {
            wrap *top = q.front();
            q.pop();
            res = top->depth;
            if (top->node->left)
            {
                q.push(new wrap(top->node->left, top->depth + 1));
            }
            if (top->node->right)
            {
                q.push(new wrap(top->node->right, top->depth + 1));
            }
        }
        return res;
    }
};
// @lc code=end
