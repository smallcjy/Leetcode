/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30204
 *
 * [128] 最长连续序列
 */


// @lcpr-template-start
#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int getmax(vector<int>& nums){
        int lianxu=1;
        int max=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if((nums[i]+1)==nums[i+1]){
                lianxu++;
                continue;
            }else{
                if(lianxu>max)max=lianxu;
                lianxu=1;
            }
        }
        if(lianxu>max)max=lianxu;
        return max;
}

vector<int> getarr(vector<int>& nums){
    map<int,int>unrepeatnums;
    vector<int> arr;
    for(int i = 0;i<nums.size();i++){
        unrepeatnums[nums[i]]++;
    }
    for(auto pair : unrepeatnums){
        arr.push_back(pair.first);
    }
    return arr;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int> curarr = getarr(nums);
        int max = getmax(curarr);
        return max;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

 */

