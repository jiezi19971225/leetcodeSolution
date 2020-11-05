/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (!prices.size())
        {
            return 0;
        }
        int minv = prices[0];
        int ret = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            minv = min(minv, prices[i]);
            ret = max(ret, prices[i] - minv);
        }

        return ret;
    }
};
// @lc code=end
