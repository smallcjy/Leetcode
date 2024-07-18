/*
 * @lc app=leetcode id=2095 lang=rust
 *
 * [2095] Delete the Middle Node of a Linked List
 */

// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }

// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn delete_middle(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        //第一步肯定是确定list的长度，这样才能确定middle的位置
        let mut sum = 0;
        let mut cur = head.as_ref();
        while cur.is_some() {
            sum += 1;
            cur = cur.unwrap().next.as_ref();
        }
        if sum <= 1 {
            return None;
        }
        let mid = sum / 2;
        let mut result = head.as_mut();
        for i in 0..(mid-1) {
            result = result.unwrap().next.as_mut();
        }
        //delete
        result.unwrap().next = result.as_mut().unwrap().next.as_mut().unwrap().next.take();

        return head;
    }
}
// @lc code=end

