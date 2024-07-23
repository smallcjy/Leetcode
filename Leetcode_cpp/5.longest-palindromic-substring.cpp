/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s)
    {
        string reserveS = reverseString(s);
        vector<char> vecS = vector<char>(s.begin(), s.end());
        vector<char> vecReS = vector<char>(reserveS.begin(), reserveS.end());
        vector<vector<int>> dp;
        // init
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> inner;
            dp.push_back(inner);
            for (int j = 0; j < s.size(); j++)
            {
                dp[i].push_back(0);
            }
        }
        for (int i = 0; i < vecS.size(); i++)
        {
            for (int j = 0; j < vecReS.size(); j++)
            {
                if (vecS[i] == vecReS[j])
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                }
            }
        }
        // 得到dp矩阵,找到最大的公共子串
        int max = 0;
        string ansS;
        for (int i = 0; i < s.size(); i++)
        {
            for (int z = 0; z < s.size(); z++)
            {
                int pos = z;
                if (dp[i][z] > max)
                {
                    std::cout << dp[i][z] << endl;
                    deque<char> ans;
                    for (int j = dp[i][z]; j > 0; j--)
                    {
                        ans.push_front(vecReS[pos]);
                        pos--;
                    }
                    if (isPalindrome(ans))
                    {
                        ansS = string(ans.begin(), ans.end());
                        max = dp[i][z];
                    }
                }
            }
        }

        return ansS;
    }

    // 判断一个string是否是回文字符串
    bool isPalindrome(deque<char> ss)
    {

        while (!ss.empty())
        {
            /* code */
            if (ss.front() != ss.back())
                return false;
            ss.pop_front();
            if (!ss.empty())
                ss.pop_back();
        }
        return true;
    }

    string reverseString(string s)
    {
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abb"\n
// @lcpr case=end

// @lcpr case=start
// "bb"\n
// @lcpr case=end

 */
