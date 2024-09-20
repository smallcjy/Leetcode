/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
 */


// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 全排列问题，使用回溯。
        vector<vector<int>> ans;
        vector<int> vfs(nums.size(), 0);
        vector<int> temp;
        n = nums.size();
        permuteNums(0, vfs, nums, temp, ans);
        return ans;
        
    }

    void permuteNums(int first, vector<int>& vfs, vector<int>& nums, vector<int> temp, vector<vector<int>>& ans) {
        if(first == n) {
            ans.push_back(temp);
            return;
        } 
        for(int i = 0; i < n; i++) {
            if(vfs[i] == 0) {
                temp.push_back(nums[i]);
                vfs[i] = 1;
                permuteNums(first + 1, vfs, nums, temp, ans);
                temp.pop_back();
                vfs[i] = 0;
            }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

