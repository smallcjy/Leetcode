/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30204
 *
 * [2] 两数相加
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

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public: 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *res = ans;
        int len = max(getLen(l1), getLen(l2));
        if(getLen(l1) > getLen(l2)) {
            l2 = fillList(l2, len);
        }else {
            l1 = fillList(l1, len);
        }
        while (l1 != nullptr && l2 != nullptr)
        {
            /* code */
            int x = l1->val;
            int y = l2->val;
            int carry = (x + y >= 10) ? 1 : 0 ;

            if (x + y >= 10) {
                ans->val = x + y - 10;
            }else {
                ans->val = x + y;
            }

            if(carry) {
                if(l1->next == nullptr) {
                    l1->next = new ListNode(1);
                    l2->next = new ListNode(0);
                }else {
                    l1->next->val++;
                }
            }

            if(l1->next != nullptr && l2->next != nullptr) {
                ans ->next = new ListNode(0);
                ans = ans->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        
        return res;
    }

    int getLen(ListNode* l) {
        int len = 0;
        while(l!= nullptr) {
            len++;
            l = l->next;
        }
        return len;
    }

    ListNode* fillList(ListNode* l, int len) {
        ListNode* cur = l;
        for(int i = 1; i < len; i++) {
            if(cur->next == nullptr) {
                cur->next = new ListNode(0);
            }
            cur = cur->next;
        }
        return l;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
