/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int ptr = 0;
        for (int i = 0; i < pushed.size(); ++i)
        {
            int top = pushed[i];
            if (top == popped[ptr])
            {
                ++ptr;
            }
            else
            {
                s.push(top);
            }
            while (s.size() && s.top() == popped[ptr])
            {
                s.pop();
                ++ptr;
            }
        }
        if (s.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
// @lc code=end
