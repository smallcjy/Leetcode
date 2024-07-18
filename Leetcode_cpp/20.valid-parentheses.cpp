/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
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
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for(int i =  0; i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')left.push(s[i]);
            if(s[i]==')'||s[i]==']'||s[i]=='}'){
                if(left.empty())return false;
                else{
                    string comp = string(1,left.top())+s[i];
                    if(comp=="()"||comp=="[]"||comp=="{}"){
                        left.pop();
                        continue;
                    }
                    else return false;
                }
            }
        }
        if(!left.empty())return false;
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */

