/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i - 1])
            {
                res = nums[i - 1];
                break;
            }
        }
        return res;
    }
};
// @lc code=end
