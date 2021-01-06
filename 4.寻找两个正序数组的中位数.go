/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	lenall := len(nums1) + len(nums2)
	if lenall % 2 == 1 {
		return float64(getKthElement(nums1,nums2,lenall / 2 + 1))
		}else{
			var ret float64
			ret += float64(getKthElement(nums1,nums2,lenall / 2)+getKthElement(nums1,nums2,lenall / 2 + 1) ) / 2
			return ret 
	}
}

func min(a,b int) int{
	if a < b {
		return a
	}
	return b
}


func getKthElement(nums1,nums2 []int,k int) int {
	index1,index2 := 0,0
	for{
		if index1 == len(nums1){
			return nums2[index2 + k - 1]
		}
		if index2 == len(nums2){
			return nums1[index1 + k - 1]
		}
		if k == 1{
			return min(nums1[index1],nums2[index2])
		}
		half := k/2
		// 比较 nums1[k/2-1] 和 nums2[k/2-1]
		newIndex1 := min(index1 + half,len(nums1)) - 1
		newIndex2 := min(index2 + half,len(nums2)) - 1
		if nums1[newIndex1] <= nums2[newIndex2] {
			k -= (newIndex1 - index1 + 1)
			index1 = newIndex1 + 1
		}else{
			k -= (newIndex2 - index2 + 1)
			index2 = newIndex2 + 1
		}
	}
	return 0
}
// @lc code=end

