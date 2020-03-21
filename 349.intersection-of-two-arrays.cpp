/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i = 0, j = 0;
        while (i < size1 && j < size2)
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if (nums1[i] < nums2[j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return res;
    }
};
// @lc code=end
