/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30204
 *
 * [62] 不同路径
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
    int uniquePaths(int m, int n) {
//dp动态规划
// 这道题目是关于计算从矩阵的左上角到右下角的所有不同路径数。我们使用动态规划（Dynamic Programming, DP）来解决这个问题。

// 动态规划原理
// 动态规划是一种通过将问题分解为更小的子问题来解决复杂问题的方法。对于这道题，我们可以将其分解为以下几个步骤：

// 定义状态：

// dp[i][j] 表示从起点 (0,0) 到达位置 (i,j) 的路径总数。
// 状态转移方程：

// 对于位置 (i,j)，它可以从上方 (i-1,j) 或左方 (i,j-1) 到达。因此，状态转移方程为： [ dp[i][j] = dp[i-1][j] + dp[i][j-1] ]
// 初始化：

// 起点 (0,0) 只有一种路径，即自身，所以 dp[0][0] = 1。
// 第一行和第一列的所有位置只能从左边或上边到达，因此它们的路径数都为 1。
// 计算结果：

// 最终结果是 dp[m-1][n-1]，即从起点到达终点的路径总数。
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */

