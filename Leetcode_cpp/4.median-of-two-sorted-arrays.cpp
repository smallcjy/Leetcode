/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums = merge_nums(nums1, nums2);
        if(nums.size() % 2 == 0) {
            std::cout<<(nums[nums.size()/2 - 1] + nums[nums.size()/2]);
            return (nums[nums.size()/2 - 1] + nums[nums.size()/2]) / 2.0; 
        } else {
            return nums[(nums.size() + 1) / 2 - 1];
        }
    }

    vector<int> merge_nums(vector<int> nums1, vector<int> nums2) {
        vector<int> ans = nums1;
        for(int i = 0; i< nums2.size(); i++) {
            ans.push_back(nums2[i]);
        }
        //sort
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

