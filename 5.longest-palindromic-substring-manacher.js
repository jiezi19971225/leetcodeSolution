/*
 * @lc app=leetcode id=5 lang=javascript
 *
 * [5] Longest Palindromic Substring
 */
/**
 * @param {string}
 * @return {string}
 */
let s = ""

function init(str) {
    let expanedStr = []
    expanedStr.push('$')
    expanedStr.push('#')
    for (let i = 0; i < str.length; i++) {
        expanedStr[i * 2 + 2] = str[i];
        expanedStr[i * 2 + 3] = '#';
    }
    expanedStr[str.length * 2 + 2] = '*';
    return expanedStr
}

var longestPalindrome = function (s) {
    if (s.length === 0) {
        return ""
    }
    let str = [...s]
    let rl = []
    str = init(str)
    let pos = 0
    let maxlen = 0
    for (let i = 0; i < str.length; i++) {
        if (i < maxlen) {
            rl[i] = Math.min(rl[2 * pos - i], maxlen - i)
        } else {
            rl[i] = 1;
        }
        while (str[i + rl[i]] === str[i - rl[i]]) {
            rl[i]++
        }
        if (rl[i] + i > maxlen) {
            maxlen = rl[i] + i
            pos = i;
        }
    }
    let maxPalLen = rl[0]
    let maxPalPos = 0
    for (let i = 0; i < rl.length; i++) {
        if (rl[i] > maxPalLen) {
            maxPalLen = rl[i]
            maxPalPos = i
        }
    }
    maxPalLen--;
    let resWithExpand = str.slice(maxPalPos - maxPalLen, maxPalPos + maxPalLen + 1)
    let res = resWithExpand.reduce(function (prev = [], val, key) {
        if (val != '#') {
            prev.push(val)
        }
        return prev
    }, [])
    res = Array.prototype.join.call(res, '')
    return res
}

longestPalindrome(s)