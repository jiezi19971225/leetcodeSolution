/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{

public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> arr;
        solve(candidates, 0, 0, target, arr);
        return result;
    }

private:
    void solve(vector<int> &candidates, int cur, int sum, int target, vector<int> &res)
    {
        // 结束条件
        if (sum == target)
        {
            result.push_back(res);
            return;
        }
        if (cur >= candidates.size())
        {
            return;
        }
        // 不取当前位置
        solve(candidates, cur + 1, sum, target, res);
        // 取当前位置
        for (int i = 1; sum + candidates[cur] * i <= target; i++)
        {
            for (int j = 0; j < i; ++j)
            {
                res.push_back(candidates[cur]);
            }
            solve(candidates, cur + 1, sum + i * candidates[cur], target, res);
            for (int j = 0; j < i; ++j)
            {
                res.pop_back();
            }
        }
    }
};
// @lc code=end
