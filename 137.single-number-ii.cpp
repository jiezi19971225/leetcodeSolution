/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = nums[nums.size() - 1];
        for (int i = 0; i < nums.size() - 1; i += 3)
        {
            if (nums[i] != nums[i + 1])
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
// @lc code=end
