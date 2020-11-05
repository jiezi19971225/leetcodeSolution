/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < m; ++i)
        {
            nums1[m + n - 1 - i] = nums1[m - 1 - i];
        }

        int i = n, j = 0, cnt = 0;
        while (i < m + n && j < n)
        {
            nums1[cnt++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }
        while (i < m + n)
        {
            nums1[cnt++] = nums1[i++];
        }
        while (j < n)
        {
            nums1[cnt++] = nums2[j++];
        }
    }
};
// @lc code=end
