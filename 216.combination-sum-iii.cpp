/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
    int maxCnt;
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        maxCnt = k;
        vector<int> arr;
        vector<int> candidates{1, 2, 3, 4, 5, 6, 7, 8, 9};
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, 0, n, arr, false, 0);
        return result;
    }

private:
    void solve(vector<int> &candidates, int cur, int sum, int target, vector<int> &res, bool preAction, int cnt)
    {
        if (sum == target && cnt == maxCnt)
        {
            result.push_back(res);
            return;
        }
        if (cur >= candidates.size() || cnt > maxCnt)
        {
            return;
        }
        solve(candidates, cur + 1, sum, target, res, false, cnt);
        if (sum + candidates[cur] <= target)
        {
            // 如果前一个元素和当前元素相同，如果前一个操作没有选择，则现在不能再选择
            if (!(cur > 0 && preAction == false && candidates[cur - 1] == candidates[cur]))
            {
                res.push_back(candidates[cur]);
                solve(candidates, cur + 1, sum + candidates[cur], target, res, true, cnt + 1);
                res.pop_back();
            }
        }
    }
};
// @lc code=end
