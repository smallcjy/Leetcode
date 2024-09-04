/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s) {
//使用栈解决, 推入左括号，与右括号识别匹配，如果出现右括号时，栈内已经没有括号了，说明无法匹配，要把右括号索引放入以记录当前位置。
        stack<int> stack;
        int maxL = 0;
        stack.push(-1);

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if(stack.empty()) {
                    stack.push(i);
                } else {
                    maxL = max(maxL, i - stack.top());
                }
            }
        }
        
        
        return maxL;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "())"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

