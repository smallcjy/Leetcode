/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * @lcpr version=30204
 *
 * [31] 下一个排列
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
    void nextPermutation(vector<int>& nums) {
        //重新排序这串数字，使得这个数字是所有比原数字大的排序中的最小的数字。

        //第一步：找到最小的相邻升序对
        int pos = -1;
        for(int i = nums.size() - 1; i > 0; i--) {
            if (nums[i-1]<nums[i]) {
                pos = i;
                break;
            }
        }

        //如果找不到这个升序对，说明是所有字典中的最后一个,直接倒叙即可
        if(pos == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //第二步：升序对的后面这个数字，从后往前找到比这个数字大的第一个数字
        int k = -1;
        for(int i = nums.size() - 1; i >= pos; i--) {
            if(nums[pos - 1] < nums[i]) {
                k = i;
                break;
            }
        }

        //第三步：对调这两个数字
        swap(nums[pos - 1], nums[k]);
        //第四步：reserve pos后面的数组
        vector<int>::iterator it = nums.begin();
        for(int i = 0; i < pos ; i++) {
            it++;
        }
        std::cout<<pos<<endl;
        std::cout<<k<<endl;
        std::cout<<*it;
        reverse(it, nums.end());
        return;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */

