/*
 * @lc app=leetcode id=2 lang=javascript
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

var addTwoNumbers = function (l1, l2) {
    let head = l3 = new ListNode()
    let jw = 0
    l3.val = 0
    l3.next = null
    while (l1 || l2) {
        jw = 0
        if (l1) {
            l3.val += l1.val
        }
        if (l2) {
            l3.val += l2.val
        }
        if (l3.val >= 10) {
            jw = 1
            l3.val -= 10
        }
        if (l1) {
            l1 = l1.next
        }
        if (l2) {
            l2 = l2.next
        }
        if (l1 || l2 || jw) {
            l3.next = new ListNode()
            l3 = l3.next
            l3.val = jw
            l3.next = null
        } else {
            l3.next = null
        }
    }
    return head
};