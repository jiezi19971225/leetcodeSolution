/*
 * @lc app=leetcode.cn id=10 lang=golang
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
package main
import (
	"fmt"
)

func isMatch(s string, p string) bool {
	lens := len(s)
	lenp := len(p)
	var dp [][]bool

	for i := 0; i <= lens; i++ {
		d := make([]bool, lenp+1)
		dp = append(dp, d)
	}
	dp[0][0] = true
	for j := 1; j <= lenp; j++ {
		if p[j-1] == '*' {
			dp[0][j] = dp[0][j-2]
		}
	}

	for i := 1; i <= lens; i++ {
		for j := 1; j <= lenp; j++ {
			if s[i-1] == p[j-1] || p[j-1] == '.' {
				dp[i][j] = dp[i][j] || dp[i-1][j-1]
			} else if p[j-1] == '*' {
				dp[i][j] = dp[i][j] || dp[i][j-2]
				if s[i-1] == p[j-2] || int(p[j-2]) == '.' {
					dp[i][j] = dp[i][j] || dp[i-1][j]
				}
			}
		}
	}
	return dp[lens][lenp]
}
// @lc code=end

