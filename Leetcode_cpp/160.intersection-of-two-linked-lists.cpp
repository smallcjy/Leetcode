/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] 相交链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
map<ListNode*,ListNode*> prior_node(ListNode *headA){
    map<ListNode*,ListNode*> prior_node;
    ListNode*& cur=headA;
    prior_node[cur] = NULL;
    while(cur->next!=NULL){
        prior_node[cur->next]=cur;
        cur = cur->next;
    }
    return prior_node;
}
 //思路：先将指针指到最后，在从后往前遍历，一直到出现不同的结果

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,ListNode*> prior_nodeA=prior_node(headA);
        map<ListNode*,ListNode*> prior_nodeB=prior_node(headB);
        ListNode*& cur_A=headA;
        ListNode*& cur_B=headB;
        while(cur_A->next!=NULL)cur_A = cur_A->next;
        while(cur_B->next!=NULL)cur_B = cur_B->next;
        while(cur_A==cur_B&&cur_A!=NULL&&cur_B!=NULL){
            if(prior_nodeA[cur_A]==NULL||prior_nodeB[cur_B]==NULL){
                return cur_A;
            }
            cur_A = prior_nodeA[cur_A];
            cur_B = prior_nodeB[cur_B];
        }
        if(cur_A->next==NULL&&cur_B->next==NULL&&cur_A->val!=cur_B->val){
            return NULL;
        }else if(cur_A->next==NULL&&cur_B->next==NULL&&cur_A==cur_B){
            return cur_A;
        }else{
            return cur_A->next;
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

