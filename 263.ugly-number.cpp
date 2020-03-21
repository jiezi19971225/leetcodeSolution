/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int num)
    {
        if (num <= 0)
        {
            return false;
        }
        int div = 2;
        while (num != 1)
        {
            if (num % div == 0)
            {
                num = num / div;
            }
            else
            {
                div++;
            }
            if (div > 5)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
