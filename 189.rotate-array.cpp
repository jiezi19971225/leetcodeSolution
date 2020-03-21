/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        int step = k % size;
        vector<int> temp;
        for (int i = size - step; i < size; i++)
        {
            temp.push_back(nums[i]);
        }
        for (int i = size - step - 1; i >= 0; i--)
        {
            nums[i + step] = nums[i];
        }
        for (int i = 0; i < step; i++)
        {
            nums[i] = temp[i];
        }
    }
};
// @lc code=end
