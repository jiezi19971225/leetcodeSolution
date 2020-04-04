/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        int repeat = 0;
        int res = 0;
        sort(A.begin(), A.end());
        int cnt;
        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i] == A[i - 1])
            {
                res -= A[i];
                repeat++;
            }
            else
            {
                cnt = min((A[i] - A[i - 1]) - 1, repeat);
                repeat -= cnt;
                res += cnt * A[i - 1] + cnt * (cnt + 1) / 2;
            }
        }

        if (repeat)
        {
            res += repeat * A[A.size() - 1] + repeat * (repeat + 1) / 2;
        }
        return res;
    }
};
// @lc code=end
