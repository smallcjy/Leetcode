/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
    vector<string> generateParenthesis(int n) {
//输入n，得到的序列长度为2n，括号的生成可以抽象成一个满二叉树，首先先来遍历所有序列长度为2的括号序列
        vector<string> ans;
        dfs(ans, "", n, 0, 0);
        return ans;
    }

    void dfs( vector<string>& res , string path, int n , int left, int right) {
        if(left > n || right > left ) return;
        
        if(path.size() == n*2) {
            res.push_back(path);
            std::cout<<"add";
            return;
        }
        path += '(';
        dfs(res, path, n, left + 1, right);
        path.pop_back();
        path += ')';
        dfs(res, path, n, left, right + 1);
        path.pop_back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

