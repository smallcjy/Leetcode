use std::collections::VecDeque;

//心得：queue具有多个round中保持序列大致顺序的能力

/*
 * @lc app=leetcode id=649 lang=rust
 *
 * [649] Dota2 Senate
 */
// @lc code=start
impl Solution {
	pub fn predict_party_victory(senate: String) -> String {
        let mut dire: VecDeque<usize> = VecDeque::new();
		let mut radiant: VecDeque<usize> = VecDeque::new();
		for (i,ch) in senate.chars().enumerate() {
			if ch == 'D' {dire.push_back(i);}
			else {radiant.push_back(i);}
		}
        for i in 0..senate.len()-1 {
            if !dire.is_empty() {
                if dire.front().unwrap() == &i {
                    radiant.pop_front();
                    
                } 
            }

            if !radiant.is_empty(){
                if radiant.front().unwrap() == &i {
                    dire.pop_front();
                }
            }

        }
        
        if !dire.is_empty() {
            return "Dire".to_string();
        }else {
            return "Radiant".to_string();
        }
    }
}   
// @lc code=end


