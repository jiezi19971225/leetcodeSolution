/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

/*
第一类 nums[start] = nums[mid] 此时无法判断在那半边找
令 start++ 即可
第二类
2 3 4 5 6 7 1 这种，也就是 nums[start] < nums[mid]。此例子中就是 2 < 5；
这种情况下，前半部分有序。因此如果 nums[start] <=target<nums[mid]，则在前半部分找，否则去后半部分找。
第三类
6 7 1 2 3 4 5 这种，也就是 nums[start] > nums[mid]。此例子中就是 6 > 2；
这种情况下，后半部分有序。因此如果 nums[mid] <target<=nums[end]。则在后半部分找，否则去前半部分找。
*/

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // to find pivot
        int i = 0, j = nums.size();
        int ret = -1;
        while (i < j)
        {
            int m = (i + j) >> 1;
            if (target == nums[m])
            {
                ret = m;
                break;
            }
            if (nums[i] == nums[m])
            {
                i++;
                continue;
            }
            else if (nums[i] < nums[m])
            {
                // 符合条件
                if (nums[i] <= target && nums[m] > target)
                {
                    j = m;
                }
                else
                {
                    i = m + 1;
                }
            }
            else
            {
                // 符合条件
                if (nums[m] < target && nums[j - 1] >= target)
                {
                    i = m + 1;
                }
                else
                {
                    j = m;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
