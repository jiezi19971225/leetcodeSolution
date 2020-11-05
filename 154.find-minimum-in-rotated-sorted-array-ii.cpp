/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // 列出可能性 决定二分策略
        // 12111
        // 12345
        // 45123
        // 34512
        int len = nums.size();
        int i = 0, j = len - 1;
        while (i < j)
        {
            int m = (i + j) >> 1;
            if (nums[i] == nums[m] && i != m)
            {
                i++;
            }
            else if (nums[i] <= nums[m] && nums[m] <= nums[j])
            {
                break;
            }
            else if (nums[i] >= nums[m] && nums[m] <= nums[j])
            {
                j = m;
            }
            else
            {
                i = m + 1;
            }
        }
        return nums[i];
    }
};
// @lc code=end
