/*
 * @lc app=leetcode id=5 lang=javascript
 *
 * [5] Longest Palindromic Substring
 */
/**
 * @param {string} s
 * @return {string}
 */
let s = "aaacccdddcccaa"

var longestPalindrome = function (s) {
    let sa = [...s]
    let res = ""
    sa.forEach(function (v, k) {
        let len = 0;
        // odd
        while (k - len >= 0 && k + len <= sa.length - 1) {
            if (sa[k - len] == sa[k + len]) {
                len++
            } else {
                break;
            }
        }
        len--;
        if (sa.slice(k - len, k + len).length >= res.length) {
            res = sa.slice(k - len, k + len + 1)
        }
        // even
        len = 0;
        while (k - len >= 0 && k + len + 1 <= sa.length - 1) {
            if (sa[k - len] == sa[k + len + 1]) {
                len++
            } else {
                break;
            }
        }
        len--;
        if (sa.slice(k - len, k + len + 1).length >= res.length) {
            res = sa.slice(k - len, k + len + 2)
        }
    })
    res = Array.prototype.join.call(res, '')
    return res
};

longestPalindrome(s)