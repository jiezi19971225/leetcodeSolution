/*
 * @lc app=leetcode id=8 lang=javascript
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function (str) {
    let maxLimit = ~(1 << 31)
    let minLimit = ~maxLimit
    let res = ""
    let symbol = 1
    let stra = [...str]
    while (stra[0] == ' ') {
        stra.shift()
    }
    if (stra[0] == '+') {
        symbol = 1
        stra.shift()
    } else if (stra[0] == '-') {
        symbol = -1
        stra.shift()
    }
    for (let i = 0; i < stra.length; i++) {
        if (stra[i] >= '0' && stra[i] <= '9') {
            res += stra[i]
        } else {
            break
        }
    }
    res = symbol * Number(res)
    console.log(res);

    if (res > maxLimit) {
        res = maxLimit
    } else if (res < minLimit) {
        res = minLimit
    }
    return res
};
// @lc code=end

myAtoi("-42 adfa")