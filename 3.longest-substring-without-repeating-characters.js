/*
 * @lc app=leetcode id=3 lang=javascript
 *
 * [3] Longest Substring Without Repeating Characters
 */
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    sa = [...s]
    let map = new Map()
    let res = 0
    let len = 0
    let start = 0
    sa.forEach(function (c, k) {
        if (map.get(c) >= start) {
            len = k - map.get(c)
            start = map.get(c) + 1
        } else {
            len++
        }
        res = Math.max(res, len)
        map.set(c, k)
    })
    // console.log(res)
    return res
};