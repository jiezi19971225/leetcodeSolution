package main

import (
	"log"
)

/*
 * @lc app=leetcode id=14 lang=golang
 *
 * [14] Longest Common Prefix
 */

// @lc code=start

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	if len(strs) == 1 {
		return strs[0]
	}
	var i int
outer:
	for i = 0; ; i++ {
		var lastVal string
		for index, val := range strs {
			if len(val) < i+1 {
				break outer
			}
			if index > 0 && val[i] != lastVal[i] {
				break outer
			}
			lastVal = val
		}
	}
	return strs[0][0:i]
}

// @lc code=end

func main() {
	log.Printf(longestCommonPrefix([]string{"abc", "aac", "aab"}))
}
