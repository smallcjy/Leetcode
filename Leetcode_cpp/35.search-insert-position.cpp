/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30204
 *
 * [35] 搜索插入位置
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
    int searchInsert(vector<int>& nums, int target) {
        //对于有序数组，优先采用二分查找
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while(left <= right) {
            if(nums[left] == target) {
                ans = left;
                break;
            } else if(nums[right] == target) {
                ans = right;
                break;
            }

            if(nums[left] < target) left++;
            if(nums[right] > target) right--;
        }

        if(ans == -1) ans = right + 1;

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */

