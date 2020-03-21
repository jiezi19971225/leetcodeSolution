/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return false;
        }
        int minn = (1 << 31) - 1;
        int maxn = ~minn;
        vector<int> minpre;
        vector<int> maxsuf;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < minn)
            {
                minn = nums[i];
            }
            minpre.push_back(minn);
        }
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] > maxn)
            {
                maxn = nums[i];
            }
            maxsuf.push_back(maxn);
        }
        reverse(maxsuf.begin(), maxsuf.end());
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if (nums[i] > minpre[i - 1] && nums[i] < maxsuf[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
