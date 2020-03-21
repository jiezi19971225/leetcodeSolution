/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
class Solution
{
public:
    int countDigitOne(int n)
    {
        if (n < 1)
        {
            return 0;
        }
        int base[20];
        vector<int> num;
        vector<int> sufsum;
        base[0] = 1;
        for (int i = 1; i < 10; ++i)
        {
            base[i] = base[i - 1] * 10;
        }

        int res = 0;
        int presum = 0;
        while (n)
        {
            int remainder = n % 10;
            n /= 10;
            num.push_back(remainder);
        }

        int b = 1;
        sufsum.push_back(num[0]);
        for (int i = 1; i < num.size(); ++i)
        {
            b *= 10;
            sufsum.push_back(sufsum[i - 1] + b * num[i]);
        }

        for (int i = num.size() - 1; i >= 0; --i)
        {
            res += presum * base[i];
            presum = presum * 10 + num[i];
            if (num[i] >= 2)
            {
                res += base[i];
            }
            else if (num[i] == 1)
            {
                if (i - 1 >= 0)
                {
                    res += sufsum[i - 1] + 1;
                }
                else
                {
                    res += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
