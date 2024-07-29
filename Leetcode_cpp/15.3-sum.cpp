/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ansSet;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > 0)
                break; // 因为数组已经排序，如果第一个数大于0，后面的数也都大于0，不可能和为0
            if (k > 0 && nums[k] == nums[k - 1])
                continue; // 跳过重复的k

            int i = k + 1, j = nums.size() - 1;
            while (i < j)
            {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum < 0)
                {
                    ++i;
                }
                else if (sum > 0)
                {
                    --j;
                }
                else
                {
                    ansSet.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1])
                        ++i; // 跳过重复的数
                    while (i < j && nums[j] == nums[j - 1])
                        --j; // 跳过重复的数
                    ++i;
                    --j;
                }
            }
        }
        return ansSet;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
