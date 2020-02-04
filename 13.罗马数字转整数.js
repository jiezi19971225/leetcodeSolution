/*
 * @lc app=leetcode.cn id=13 lang=javascript
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
  let res = 0;
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
    while (s.length && s[0] === val) {
      res += key;
      s = s.substr(1);
    }
    if (key === 1000 && s.length >= 2 && s.substr(0, 2) === "CM") {
      res += 900;
      s = s.substr(2);
    } else if (key === 500 && s.length >= 2 && s.substr(0, 2) === "CD") {
      res += 400;
      s = s.substr(2);
    } else if (key === 100 && s.length >= 2 && s.substr(0, 2) === "XC") {
      res += 90;
      s = s.substr(2);
    } else if (key === 50 && s.length >= 2 && s.substr(0, 2) === "XL") {
      res += 40;
      s = s.substr(2);
    } else if (key === 10 && s.length >= 2 && s.substr(0, 2) === "IX") {
      res += 9;
      s = s.substr(2);
    } else if (key === 5 && s.length >= 2 && s.substr(0, 2) === "IV") {
      res += 4;
      s = s.substr(2);
    }
  });
  return res;
};
console.log(romanToInt("MCMXCIV"));
// @lc code=end
