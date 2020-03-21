/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        if (digits.size() == 0)
        {
            return res;
        }
        int num = 0;
        int jw = 0;
        ++digits[digits.size() - 1];
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            int t = digits[i] + jw;
            jw = 0;
            if (t >= 10)
            {
                t = 0;
                jw = 1;
            }
            res.push_back(t);
        }
        if (jw)
        {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
