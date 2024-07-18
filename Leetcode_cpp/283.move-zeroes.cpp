/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30204
 *
 * [283] 移动零
 */


// @lcpr-template-start
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(int &a, int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator zeros=nums.begin();
        vector<int>::iterator unzeros;
       for(unzeros=nums.begin();unzeros!=nums.end();unzeros++){
            if(*unzeros==0)continue;
            while(*zeros!=0){
                zeros++;
                if(zeros==nums.end())return;
            }
            if(zeros<unzeros)swap(*zeros,*unzeros);
            
       }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

