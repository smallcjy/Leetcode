/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //通过动态更新merge数组，下一个interval在merge中的最后一个interval存在重叠时，更新这个interval，反之，讲下一个interval推入merge。
        //注意重叠的情况包括部分重叠和完全重叠，前者merge.back()[1]更新为merge进来的interval[1]，后者merge.back()[1]不变
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merge;
        for(const auto &interval: intervals) {
            if(merge.empty() || interval[0] > merge.back()[1]) {
                merge.push_back(interval);
            } else {
                merge.back()[1] = max(merge.back()[1], interval[1]);
            }
            
        }
        return merge;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

