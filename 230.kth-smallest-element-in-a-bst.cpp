/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int result = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        int cur = 0;
        _inOrderTraversal(root, cur, k);
        return result;
    }

private:
    void _inOrderTraversal(TreeNode *root, int &cur, int k)
    {
        if (root == NULL || cur >= k)
        {
            return;
        }
        _inOrderTraversal(root->left, cur, k);
        ++cur;
        if (cur == k)
        {
            result = root->val;
            return;
        }
        _inOrderTraversal(root->right, cur, k);
    }
};
// @lc code=end
