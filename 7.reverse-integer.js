/*
 * @lc app=leetcode id=7 lang=javascript
 *
 * [7] Reverse Integer
 */

// @lc code=start
/**
 * @param {number} x
 * @return {number}
 */
let x = 123
var reverse = function (x) {

    let sx = [...(x + "")]
    let symbol = 1;
    if (sx[0] == '-') {
        symbol = -1
        sx.shift()
    }
    sx.reverse()
    while (sx[0] == '0' && sx.length > 1) {
        sx.shift()
    }
    let res = symbol * parseInt(sx.join(''))

    let maxLimit = ~(1 << 31)
    let minLimit = ~maxLimit

    if (res > maxLimit || res < minLimit) {
        return 0
    }

    return res;
};
// @lc code=end
reverse(x)