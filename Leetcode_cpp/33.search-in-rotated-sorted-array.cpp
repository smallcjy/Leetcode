/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30204
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int>& nums, int target) {
        //旋转排序数组有个特征是除了某段下降外，其余全为升序数组。
        //对于有序数组使用二分查找比较快

        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }

            //判断此时mid属于哪部分有序数列
            if (nums[left] <= nums[mid]) {
                //左半序列
                if(nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                //右半序列
                if(nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid -1;
                }
            }
        }
        return -1;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

