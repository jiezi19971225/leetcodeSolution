/*
 * @lc app=leetcode.cn id=11 lang=golang
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
package main

import (
	"fmt"
)

func maxArea(height []int) int {
	left, right := 0, len(height)-1
	res := 0
	for left < right {
		minHeight := 0
		if height[left] < height[right] {
			minHeight = height[left]
		} else {
			minHeight = height[right]
		}

		newArea := (right - left) * minHeight
		if newArea > res {
			res = newArea
		}

		if height[left] < height[right] {
			newLeft := left + 1
			for newLeft < right && height[newLeft] < height[left] {
				newLeft = newLeft + 1
			}
			left = newLeft
		} else {
			newRight := right - 1
			for newRight > left && height[newRight] < height[right] {
				newRight = newRight - 1
			}
			right = newRight
		}
	}
	return res
}

func main(){
	fmt.Print(maxArea([]int{1,2,3,4}))
}
// @lc code=end

