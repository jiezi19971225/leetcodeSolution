/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void devide(vector<int> &nums, int start, int end)
    {
        if (start < end)
        {
            int m = (start + end) >> 1;
            devide(nums, start, m);
            devide(nums, m + 1, end);
            merge(nums, start, m, end);
        }
    }
    void merge(vector<int> &nums, int start, int mid, int end)
    {
        int i = start, j = mid + 1, m = mid, n = end;
        vector<int> temp;
        while (i <= m && j <= n)
        {
            if (nums[i] <= nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else
            {
                temp.push_back(nums[j++]);
            }
        }
        while (i <= m)
        {
            temp.push_back(nums[i++]);
        }
        while (j <= n)
        {
            temp.push_back(nums[j++]);
        }
        for (int k = 0; k < end - start + 1; ++k)
        {
            nums[start + k] = temp[k];
        }
    }
    void sortColors(vector<int> &nums)
    {
        devide(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
