/*
 * @lc app=leetcode id=219 lang=golang
 *
 * [219] Contains Duplicate II
 */
package main

import (
	"fmt"
)

// @lc code=start

func containsNearbyDuplicate(nums []int, k int) bool {
	res := false
	m := map[int]int{}
	for index, value := range nums {
		if v, ok := m[value]; ok {
			if index-v <= k {
				res = true
			}
		}
		m[value] = index
	}
	return res
}

// @lc code=end

func main() {
	fmt.Print(containsNearbyDuplicate([]int{1, 2, 3, 1, 2, 3}, 2))
}
