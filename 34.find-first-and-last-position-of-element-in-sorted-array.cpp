/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        int i = 0, j = nums.size();
        int i2 = 0, j2 = nums.size();
        bool ok = false;
        while (i < j)
        {
            int mid = (i + j) >> 1;
            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                if (nums[mid] == target)
                {
                    ok = true;
                }
                j = mid;
            }
        }
        while (i2 < j2)
        {
            int mid = (i2 + j2) >> 1;
            if (nums[mid] <= target)
            {
                i2 = mid + 1;
            }
            else
            {
                j2 = mid;
            }
        }
        if (ok)
        {
            res.push_back(i);
            res.push_back(i2 - 1);
        }
        else
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};
// @lc code=end
