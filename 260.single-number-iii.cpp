/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> result;
        int xor2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            xor2 ^= nums[i];
        }
        int mask = -xor2 & xor2;
        int result1 = 0, result2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] & mask)
            {
                result1 ^= nums[i];
            }
            else
            {
                result2 ^= nums[i];
            }
        }
        result.push_back(result1);
        result.push_back(result2);
        return result;
    }
};
// @lc code=end
