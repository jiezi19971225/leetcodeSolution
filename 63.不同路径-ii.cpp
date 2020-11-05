/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        long long dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i - 1 >= 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
