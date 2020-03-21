/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int res = 0;
        int size = nums.size();
        int bucket[size + 1];
        memset(bucket, 0, sizeof(bucket));
        for (int i = 0; i < size; ++i)
        {
            bucket[nums[i]]++;
            if (bucket[nums[i]] > 1)
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
// @lc code=end
