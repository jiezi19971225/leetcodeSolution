/*
 * @lc app=leetcode id=217 lang=golang
 *
 * [217] Contains Duplicate
 */
package main

import "sort"

// @lc code=start
func containsDuplicate(nums []int) bool {
	sort.Ints(nums)
	ok := false
	for k, v := range nums {
		if k > 0 && v == nums[k-1] {
			ok = true
		}
	}
	return ok
}

// @lc code=end

func main() {

}
