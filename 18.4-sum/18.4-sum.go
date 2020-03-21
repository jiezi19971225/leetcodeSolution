/*
 * @lc app=leetcode id=18 lang=golang
 *
 * [18] 4Sum
 */
package main

import (
	"fmt"
	"sort"
)

// @lc code=start

func threeSum(nums []int, target int) [][]int {

	var res [][]int
	sort.Ints(nums)
	numslen := len(nums)
	lastRes := []int{-1, -1, -1}
	for index, val := range nums[:numslen-2] {
		if index > 0 && val == nums[index-1] {
			continue
		}
		l, r := index+1, numslen-1
		need := target - val
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

func fourSum(nums []int, target int) [][]int {
	if len(nums) < 4 {
		return [][]int{}
	}

	sort.Ints(nums)
	res := [][]int{}
	numslen := len(nums)

	for index, val := range nums[:numslen-3] {
		if index > 0 && val == nums[index-1] {
			continue
		}
		if val+nums[numslen-1]*3 < target {
			continue
		}
		if val*4 > target {
			break
		}
		need := target - val
		threeRes := threeSum(nums[index+1:], need)
		for _, r := range threeRes {
			newRes := make([]int, 4)
			newRes[0] = val
			copy(newRes[1:], r)
			res = append(res, newRes)
		}
	}
	return res
}

// @lc code=end

func main() {
	fmt.Print(fourSum([]int{1, 0, -1, 0, -2, 2}, 0))
}
