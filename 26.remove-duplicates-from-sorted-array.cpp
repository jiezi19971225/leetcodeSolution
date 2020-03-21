/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int ptr = 0;
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        for (int i = 1; i < size; ++i)
        {
            if (nums[i] != nums[ptr])
            {
                nums[++ptr] = nums[i];
            }
        }
        return ptr + 1;
    }
};
// @lc code=end
