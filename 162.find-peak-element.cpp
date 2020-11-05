/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // 12348
        // 52341
        // 12321
        int len = nums.size();
        int i = 0, j = len - 1;
        while (i < j)
        {
            int m = (i + j) >> 1;
            // peek in left
            if (nums[m] > nums[m + 1])
            {
                j = m;
            }
            else
            {
                i = m + 1;
            }
        }
        return i;
    }
};
// @lc code=end
