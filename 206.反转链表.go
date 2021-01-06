/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	var newList *ListNode

	for head != nil {
		newNode := new(ListNode)
		newNode.Val = head.Val
		newNode.Next = newList
		newList = newNode
		head = head.Next
	}
	return newList
}
// @lc code=end

