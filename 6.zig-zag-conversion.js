/*
 * @lc app=leetcode id=6 lang=javascript
 *
 * [6] ZigZag Conversion
 */
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */

let str = "A"

var convert = function (s, numRows) {
    if (numRows === 1) {
        return s
    }
    let sa = [...s]
    let res = Array.from({
        length: numRows
    }).fill("")
    let mod = (numRows - 1) * 2
    sa.forEach(function (val, key) {
        let pos = key % mod
        if (pos === 0) {
            res[0] += val
        } else if (pos === numRows - 1) {
            res[numRows - 1] += val
        } else {
            if (pos > numRows - 1) {
                pos = (numRows - 1) * 2 - pos
            }
            res[pos] += val
        }
    })
    res = res.reduce(function (prev, val, key) {
        prev += val
        return prev
    }, "")
    console.log(res);
    return res
};

convert(str, 1)