/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 * 	最优做法是马拉车算法，但是一般面试不会考这么偏门的，可以用简单的动态规划来解决，需要考虑边界问题
 */

// @lc code=start
func longestPalindrome(s string) string {

	var dp [1005][1005]bool
	maxLen := 0
	left := 0
	right := 0
	for l := 1; l <= len(s);l++ {
		for i := 0; i < len(s)-1; i++ {
			j := i + l - 1
			if j >= len(s) {
				j = len(s) - 1
			}
			if l == 1 {
				dp[i][j] = true
			} else if i+1 > j-1 {
				dp[i][j] = s[i] == s[j]
			}else{
				dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
			}
			if dp[i][j] {
				if j - i + 1 > maxLen {
					maxLen = j - i + 1
					left = i
					right = j
				}
			}
		}
	}
	return s[left:right+1]
}
// @lc code=end

