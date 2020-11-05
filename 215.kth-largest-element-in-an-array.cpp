/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
    static bool cmp(int a,int b){
        return a>b;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        return nums[k-1];
    }
};
// @lc code=end