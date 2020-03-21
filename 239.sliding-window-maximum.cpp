/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (dq.size() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            // 判断是否已经超过窗口范围
            if (dq.front() + k <= i)
            {
                dq.pop_front();
            }
            if (i >= k - 1)
            {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end
