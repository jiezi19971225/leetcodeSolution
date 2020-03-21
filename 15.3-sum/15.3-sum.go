/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 */
package main

import (
	"fmt"
	"sort"
)

// @lc code=start
func threeSum(nums []int) [][]int {

	if len(nums) < 3 {
		return [][]int{}
	}

	var res [][]int
	sort.Ints(nums)
	numslen := len(nums)
	lastRes := []int{-1, -1, -1}
	for index, val := range nums[:numslen-2] {
		if index > 0 && val == nums[index-1] {
			continue
		}
		l, r := index+1, numslen-1
		need := -val
		for l < r {
			if nums[l]+nums[r] == need {
				if lastRes[0] != nums[index] || lastRes[1] != nums[l] || lastRes[2] != nums[r] {
					newRes := []int{nums[index], nums[l], nums[r]}
					res = append(res, newRes)
					copy(lastRes, newRes)
				}
				l++
				r--
			} else if nums[l]+nums[r] < need {
				l++
			} else {
				r--
			}
		}
	}
	return res
}

// @lc code=end

func main() {
	fmt.Print(threeSum([]int{-1, 0, 1, 2, -1, -4}))
}
