/*

 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    struct node
    {
        char c;
        int index;
        node(char c, int index) : c(c), index(index) {}
    };

    int longestValidParentheses(string s)
    {
        stack<node> stk;
        for (int i = 0; i < s.length(); ++s)
        {
            if (s[i] == '(')
            {
                stk.push(node('(', i));
            }
            else
            {
                node top = stk.top();
                if (top.c == '(')
                {
                    top.pop();
                }
                else
                {
                    stk.push(node(')', i));
                }
            }
        }
        int last = s.length - 1;
        int ret = 0;
        while (!stk.size())
        {
            node top = stk.top();
            stk.pop();
            ret = max(ret, last - top.index);
            last = top.index;
        }
        ret = max(ret, last);
        return ret;
    }
};
// @lc code=end
