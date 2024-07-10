/*
 * @lc app=leetcode id=933 lang=rust
 *
 * [933] Number of Recent Calls
 */

use std::collections::VecDeque;


// @lc code=start
struct RecentCounter {
    queue: VecDeque<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {

    fn new() -> Self {
        return RecentCounter {
            queue: VecDeque::new(),
        };
    }
    
    fn ping(&mut self, t: i32) -> i32 {
        self.queue.push_back(t);
        //检查queue中在t-3000，t之间的个数
        let mut result = 0;
        let mut temp = self.queue.clone();
        let small = &t - 3000;
        while temp.front().unwrap() <  &small{
            temp.pop_front();
        }
        return temp.len() as i32;
    }
}

// /**
//  * Your RecentCounter object will be instantiated and called as such:
//  * let obj = RecentCounter::new();
//  * let ret_1: i32 = obj.ping(t);
//  */
// @lc code=end

pub fn test(){
    let mut obj = RecentCounter::new();
    for i in [1, 100, 3001, 3002] {
        println!("{}", obj.ping(i));
    }
}
