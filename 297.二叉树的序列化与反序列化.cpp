#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec
{
public:
    void solve(TreeNode *root, string &res)
    {
        if (!root)
        {
            res += "null,";
            return;
        }
        res += to_string(root->val) + ",";
        solve(root->left, res);
        solve(root->right, res);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        if (!root)
        {
            return res;
        }
        solve(root, res);
        return res.substr(0, res.length() - 1);
    }
    TreeNode *solve1(vector<string> tokens, int &pos)
    {
        if (tokens[pos] == "null")
        {
            ++pos;
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(tokens[pos]));
        ++pos;
        root->left = solve1(tokens, pos);
        root->right = solve1(tokens, pos);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
        {
            return NULL;
        }
        vector<string> tokens;
        string token = "";
        for (int i = 0; i < data.length(); ++i)
        {
            if (data[i] == ',')
            {
                tokens.push_back(token);
                token = "";
            }
            else
            {
                token += data[i];
            }
        }
        int pos = 0;
        TreeNode *res = solve1(tokens, pos);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
