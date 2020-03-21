/*
 * @lc app=leetcode id=167 lang=golang
 *
 * [167] Two Sum II - Input array is sorted
 */

package main

// @lc code=start
func twoSum(numbers []int, target int) []int {
	res := make([]int, 2, 2)
	i := 0
	j := len(numbers) - 1
	for i < j {
		if numbers[i]+numbers[j] == target {
			res[0] = i + 1
			res[1] = j + 1
			break
		} else if numbers[i]+numbers[j] < target {
			i++
		} else {
			j--
		}
	}
	return res
}

// @lc code=end

func main() {
	twoSum([]int{2, 7, 11, 15}, 9)
}
