/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30204
 *
 * [21] 合并两个有序链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:  
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*& cur1 = list1;
        ListNode*& cur2 = list2;
        queue<ListNode*> queue;
        while(cur1!=nullptr&&cur2!=nullptr){
            if(cur1->val<=cur2->val){
                queue.push(cur1);
                cur1 = cur1->next;
            }else{
                queue.push(cur2);
                cur2 = cur2->next;
            }
        }
        if(cur1==nullptr)queue.push(cur2);
        else queue.push(cur1);
        //连接
        ListNode* ans = queue.front();
        ListNode* cur3 = ans;
        queue.pop();
        while(!queue.empty()){
            cur3->next = queue.front();
            queue.pop();
            cur3 = cur3->next;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

