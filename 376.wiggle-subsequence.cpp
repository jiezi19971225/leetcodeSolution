/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int ret = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0)
            {
                cnt++;
            }
            else
            {
                int diff = nums[i] - nums[i - 1];
            }
        }
    };
}
// @lc code=end
