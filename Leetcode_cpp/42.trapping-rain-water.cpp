/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
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
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        //接雨水问题主要是使用双指针，需要两个变量记录left_max和right_max。
        //max变量是为了决定是否计算当前指针所指的height的盛水量。
        //如果指针所指height大于等于max，更新max，不计算
        //如果指针所指height小于max，不更新max，计算当前所指的盛水量并更新到ans中
        //哪边的指针的height小就移动那边的指针
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0, right_max = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= left_max)
                {
                    left_max = height[left];
                }
                else
                {
                    ans += left_max - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= right_max)
                {
                    right_max = height[right];
                }
                else
                {
                    ans += right_max - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
