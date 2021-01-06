/*
 * @lc app=leetcode.cn id=19 lang=typescript
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
  let curnode: ListNode = head
  let len = 0
  while (curnode !== null) {
    len++
    curnode = curnode.next
  }
  curnode = head
  let prenode: ListNode = head
  let curpos = len
  while (curnode) {
    if (curpos === n) {
      if (curpos === len) {
        head = head.next
      } else if (curpos === 1) {
        prenode.next = null
      } else {
        prenode.next = curnode.next
      }
      prenode.next = curnode
      break
    }
    curpos --
    prenode = curnode
    curnode = curnode.next
  }
    return head
};
// @lc code=end

