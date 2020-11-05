/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // 12345
        // 45123
        // 34512
        int len = nums.size();
        int i = 0, j = len - 1;
        while (i < j)
        {
            int m = (i + j) >> 1;
            if (nums[i] < nums[m] && nums[m] < nums[j])
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
