/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30204
 *
 * [41] 缺失的第一个正数
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
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // 首先对数组进行排序。
        // 初始化一个变量 ans 为 1，表示我们要找的最小正整数。
        // 遍历排序后的数组：
        // 如果当前元素小于等于 0，跳过。
        // 如果当前元素等于 ans，则将 ans 增加 1。
        // 如果当前元素大于 ans，则直接返回 ans。
        // 如果遍历结束后没有找到缺失的正整数，则返回 ans。
        sort(nums.begin(), nums.end());

        if (nums[0] > 1)
        {
            return 1;
        }

        int left = 0;
        int ans = 1;
        while (left <= nums.size() - 1)
        {
            if (nums[left] <= 0)
            {
                left++;
                continue;
            }
            if (nums[left] == ans)
            {
                ans++;
            }
            else if (nums[left] > ans)
            {
                break;
            }
            left++;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */
