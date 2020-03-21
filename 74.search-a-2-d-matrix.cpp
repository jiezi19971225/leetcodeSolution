/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        if (rows == 0)
        {
            return false;
        }
        int cols = matrix[0].size();
        if (cols == 0)
        {
            return false;
        }
        int left = 0, right = rows;
        int pos = -1;
        while (left < right)
        {
            int mid = left + right >> 1;
            if (matrix[mid][cols - 1] < target)
            {
                left = mid + 1;
            }
            else if (matrix[mid][0] > target)
            {
                right = mid;
            }
            else
            {
                pos = mid;
                break;
            }
        }
        if (pos == -1)
        {
            return false;
        }

        left = 0, right = cols;
        while (left < right)
        {
            int mid = left + right >> 1;
            if (matrix[pos][mid] < target)
            {
                left = mid + 1;
            }
            else if (matrix[pos][mid] > target)
            {
                right = mid;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
