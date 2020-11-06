/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

class Solution
{
    struct item
    {
        item(int value, int cnt) : value(value), cnt(cnt){};
        int value;
        int cnt;
    };
    static int cmp(item item1, item item2)
    {
        return item1.cnt > item2.cnt;
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), less<int>());
        int cnt = 0;
        vector<item> items;
        vector<int> ret;
        int last = 0;
        for (auto i : nums)
        {
            if (cnt == 0)
            {
                last = i;
                cnt++;
            }
            else if (i != last)
            {
                items.push_back(item(last, cnt));
                last = i;
                cnt = 1;
            }
            else
            {
                last = i;
                cnt++;
            }
        }
        items.push_back(item(last, cnt));
        sort(items.begin(), items.end(), cmp);
        for (int i = 0; i < k; ++i)
        {
            ret.push_back(items[i].value);
        }
        return ret;
    }
};
// @lc code=end
