/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30204
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s)
    {
        vector<char> chars(s.begin(), s.end());
        deque<char> nonRepeatString;
        unordered_map<char, int> appearSum;
        int max = 0;
        int cur = 0;
        for (int i = 0; i < chars.size(); i++)
        {
            while (true)
            {
                auto found = appearSum.find(chars[i]);
                if (found == appearSum.end())
                    break;
                appearSum.erase(nonRepeatString.front());
                nonRepeatString.pop_front();
                cur--;
            }
            nonRepeatString.push_back(chars[i]);
            appearSum.emplace(chars[i], 1);
            cur++;
            if (cur > max)
                max = cur;
        }
        return max;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
