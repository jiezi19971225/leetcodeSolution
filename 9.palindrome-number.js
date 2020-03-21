/*
 * @lc app=leetcode id=9 lang=javascript
 *
 * [9] Palindrome Number
 */

// @lc code=start
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let sa = [...x.toString()];
    for (let i = 0; i < sa.length / 2; i++) {
        if (sa[i] != sa[sa.length - 1 - i]) {
            return false;
        }
    }
    return true;
};
// @lc code=end
