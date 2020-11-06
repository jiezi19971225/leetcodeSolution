/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
    static int cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ret;
        if (!intervals.size())
        {
            return ret;
        }

        int start, end;
        bool isFirst = true;
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto x : intervals)
        {
            int nstart = x[0], nend = x[1];
            if (isFirst)
            {
                start = nstart;
                end = nend;
                isFirst = false;
            }
            // overlap
            if (end >= nstart)
            {
                end = max(end, nend);
            }
            else
            {
                vector<int> tmp{start, end};
                ret.push_back(tmp);
                start = nstart;
                end = nend;
            }
        }
        vector<int> tmp{start, end};
        ret.push_back(tmp);
        return ret;
    }
};
// @lc code=end
