/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
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
    vector<vector<string>> solveNQueens(int n) {
        int row = 0;
        vector<string> cur(n, string(n, '.'));
        vector<vector<string>> ans;
        backtrack(n, row, cur, ans);
        return ans;
    }

    void backtrack(int n, int row, vector<string>& cur, vector<vector<string>>& ans){
        if (row == n) {
            ans.push_back(cur);
            return;
        }

        for (int col = 0; col < n; col++) {
            //二维回溯、for循环的每个循环是一个一维回溯
            //for循环的每个循环决定每一列的棋子摆放
            //如果check后发现不能摆放Q，说明这一列的下面的位置也不能摆放Q，直接进入下个循环
            if (check(cur, row, col, n)) {
                cur[row][col] = 'Q';
                backtrack(n, row + 1, cur, ans);
                cur[row][col] = '.';
            }
        }
    }

    bool check(const vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

