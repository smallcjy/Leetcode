/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
 */


// @lcpr-template-start
using namespace std;
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //对于遍历搜索答案的问题使用回溯法
        //对于不希望有重复情况出现的情况下，可以向前遍历
        vector<int> cur;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        getSum(candidates, 0, target, 0, cur, ans);
        return ans;
        
    }

    void getSum(vector<int>& candidates, int layer, int target, int sum, vector<int> cur,  vector<vector<int>>& ans) {
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(cur);
            return;
        }

        for(int i = layer; i < candidates.size(); i++) {
            sum += candidates[i];
            cur.push_back(candidates[i]);
            getSum(candidates, i, target, sum, cur, ans);
            cur.pop_back();
            sum -= candidates[i];
        }


    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

