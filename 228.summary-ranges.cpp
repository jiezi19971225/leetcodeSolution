/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution
{
    const int inf = 1e9 + 7;

public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.size() == 0)
        {
            return res;
        }
        int len = 0;
        int left, right;
        stringstream sout;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
            {
                left = i;
                len = 1;
            }
            else if (nums[i] != nums[i - 1] + 1)
            {
                if (len >= 2)
                {
                    sout << nums[left] << "->" << nums[right];
                }
                else
                {
                    sout << nums[left];
                }
                res.push_back(sout.str());
                sout.str("");
                left = i;
                len = 1;
            }
            else
            {
                right = i;
                ++len;
            }
        }
        if (len >= 2)
        {
            sout << nums[left] << "->" << nums[right];
        }
        else
        {
            sout << nums[left];
        }
        res.push_back(sout.str());
        sout.str("");
        return res;
    }
};
// @lc code=end
