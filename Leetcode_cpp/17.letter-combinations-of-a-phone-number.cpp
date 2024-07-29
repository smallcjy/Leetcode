/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
 */

// @lcpr-template-start
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    //回溯迭代算法
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> ans;
        string current = "";
        int index = 0;
        backtrace(digits, phoneMap, 0, current, ans);

        return ans;
    }
    void backtrace(const string &digits, const unordered_map<char, string> phoneMap, int index, string current, vector<string> &ans)
    {
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        char digit = digits[index];
        const string &letters = phoneMap.at(digit);
        for (char letter : letters)
        {
            current += letter;
            backtrace(digits, phoneMap, index + 1, current, ans);
            current.pop_back();
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
