/*
 * @lc app=leetcode id=10 lang=javascript
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
  var dp = Array.from({ length: s.length + 2 }, x =>
    Array(p.length + 2).fill(false)
  );
  s += "#";
  p += "#";
  dp[s.length][p.length] = true;
  for (let i = s.length - 1; i >= 0; i--) {
    for (let j = p.length - 1; j >= 0; j--) {
      if (j === 0) {
        //debugger;
      }
      if ((s[i] === p[j] || p[j] === ".") && p[j + 1] !== "*") {
        dp[i][j] = dp[i + 1][j + 1];
        if (p[j + 2] === "*") {
          dp[i][j] = dp[i][j] || dp[i + 1][j + 3];
        }
      } else if (p[j] === "*") {
      } else if (p[j + 1] === "*") {
        if (p[j] === "." || p[j] === s[i]) {
          dp[i][j] = dp[i][j + 2] || dp[i + 1][j] || dp[i + 1][j + 2];
        } else {
          dp[i][j] = dp[i][j + 2];
        }
      }
      console.log(i, j, dp[i][j]);
    }
  }
  return dp[0][0];
};
s = "";
p = "c*c*";
console.log(isMatch(s, p));
// @lc code=end
