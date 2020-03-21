/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, 0, target, arr, false);
        return result;
    }

private:
    void solve(vector<int> &candidates, int cur, int sum, int target, vector<int> &res, bool preAction)
    {
        if (sum == target)
        {
            result.push_back(res);
            return;
        }
        if (cur >= candidates.size())
        {
            return;
        }
        solve(candidates, cur + 1, sum, target, res, false);
        if (sum + candidates[cur] <= target)
        {
            // 如果前一个元素和当前元素相同，如果前一个操作没有选择，则现在不能再选择
            if (!(cur > 0 && preAction == false && candidates[cur - 1] == candidates[cur]))
            {
                res.push_back(candidates[cur]);
                solve(candidates, cur + 1, sum + candidates[cur], target, res, true);
                res.pop_back();
            }
        }
    }
};
// @lc code=end
