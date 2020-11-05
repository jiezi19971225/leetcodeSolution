/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (j == i)
                {
                    dp[j] = dp[j - 1] + triangle[i][j];
                }
                else if (j == 0)
                {
                    dp[j] = dp[j] + triangle[i][j];
                }
                else
                {
                    dp[j] = min(dp[j - 1] + triangle[i][j], dp[j] + triangle[i][j]);
                }
            }
        }
        int ret = dp[0];
        for (int i = 0; i < n; ++i)
        {
            ret = min(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end
