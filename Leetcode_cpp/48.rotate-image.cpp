/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30204
 *
 * [48] 旋转图像
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
    void rotate(vector<vector<int>>& matrix) {
        //矩阵旋转
        //先转置，再翻转
        int n = matrix.size();
        //这是转置矩阵的操作，希望能记住
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
        //再翻转，翻转j只用翻转一半，n／2
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
        return ;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */

