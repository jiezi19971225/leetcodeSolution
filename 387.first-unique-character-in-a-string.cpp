/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int sset[26];
        int pos[26];
        int res = 1 << 30;
        memset(sset, 0, sizeof(sset));
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < s.length(); ++i)
        {
            int cn = s[i] - 97;
            sset[cn]++;
            pos[cn] = i;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (sset[i] == 1)
            {
                res = min(res, pos[i]);
            }
        }
        return res == 1 << 30 ? -1 : res;
    }
};
// @lc code=end
