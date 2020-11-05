/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long i = 1, j = n;
        while (i < j)
        {
            long long m = (i + j) >> 1;
            bool isBad = isBadVersion(m);
            if (isBad)
            {
                j = m;
            }
            else
            {
                i = m + 1;
            }
        }
        return i;
    }
};
// @lc code=end
