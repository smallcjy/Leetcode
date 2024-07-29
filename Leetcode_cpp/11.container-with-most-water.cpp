/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30204
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0;
        int j = height.size()-1;
        while(true) {
            if(i==j) break;
            int v = min(height[i], height[j]) * (j - i);
            if(v>max) max = v;
            //j值发生变化你还用j值去判断？
            if(height[i] >= height[j]){
                j--;
            }else{
                i++;
            }
        }
        return max;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

