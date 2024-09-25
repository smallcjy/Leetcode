/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> ans;
        //move
        while(top <= bottom && left <= right) {
            // 从左到右
            for (int col = left; col <= right; ++col) {
                ans.push_back(matrix[top][col]);
            }
            ++top;

            // 从上到下
            for (int row = top; row <= bottom; ++row) {
                ans.push_back(matrix[row][right]);
            }
            --right;

            if (top <= bottom) {
                // 从右到左
                for (int col = right; col >= left; --col) {
                    ans.push_back(matrix[bottom][col]);
                }
                --bottom;
            }

            if (left <= right) {
                // 从下到上
                for (int row = bottom; row >= top; --row) {
                    ans.push_back(matrix[row][left]);
                }
                ++left;
            }
        }
                return ans;
        }
    
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

