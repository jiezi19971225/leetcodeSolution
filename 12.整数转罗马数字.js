/*
 * @lc app=leetcode.cn id=12 lang=javascript
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
  let res = "";
  const m = new Map([
    [1000, "M"],
    [500, "D"],
    [100, "C"],
    [50, "L"],
    [10, "X"],
    [5, "V"],
    [1, "I"]
  ]);
  m.forEach((val, key) => {
    count = Number.parseInt(num / key);
    res += val.repeat(count);
    num -= count * key;
    if (key === 1000 && num >= 900) {
      num = num - 900;
      res += "CM";
    } else if (key === 500 && num >= 400) {
      num = num - 400;
      res += "CD";
    } else if (key === 100 && num >= 90) {
      num = num - 90;
      res += "XC";
    } else if (key === 50 && num >= 40) {
      num = num - 40;
      res += "XL";
    } else if (key === 10 && num >= 9) {
      num = num - 9;
      res += "IX";
    } else if (key === 5 && num >= 4) {
      num = num - 4;
      res += "IV";
    }
  });
  return res;
};
console.log(intToRoman(3));
// @lc code=end
