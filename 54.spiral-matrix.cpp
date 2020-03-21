/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
    int mov[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int rows = matrix.size();
        if (rows == 0)
        {
            return res;
        }
        int cols = matrix[0].size();
        if (cols == 0)
        {
            return res;
        }
        int vis[rows][cols];
        memset(vis, 0, sizeof(vis));
        int pi = 0, pj = 0;
        vis[0][0] = 1;
        res.push_back(matrix[pi][pj]);
        while (1)
        {
            int fin = true;
            for (int i = 0; i < 4; ++i)
            {
                if (i == 0)
                {
                    int ni = pi + mov[3][0], nj = pj + mov[3][1];
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && !vis[ni][nj])
                    {
                        continue;
                    }
                }
                int ni = pi + mov[i][0], nj = pj + mov[i][1];
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && !vis[ni][nj])
                {
                    pi = ni, pj = nj;
                    vis[ni][nj] = 1;
                    res.push_back(matrix[ni][nj]);
                    fin = false;
                    break;
                }
            }
            if (fin)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
