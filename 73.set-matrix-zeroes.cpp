/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
        {
            return;
        }
        int cols = matrix[0].size();
        if (cols == 0)
        {
            return;
        }
        set<int> rowset;
        set<int> colset;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rowset.insert(i);
                    colset.insert(i);
                }
            }
        }
        for (auto row : rowset)
        {
            for (int i = 0; i < cols; ++i)
            {
                matrix[row][i] = 0;
            }
        }
        for (auto col : colset)
        {
            for (int i = 0; i < rows; ++i)
            {
                matrix[i][col] = 0;
            }
        }
    }
};
// @lc code=end
