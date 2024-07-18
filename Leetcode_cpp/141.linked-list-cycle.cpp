/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30204
 *
 * [141] 环形链表
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
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //建立一个当前已访问节点的hash
        map<ListNode*,int>nodes;
        ListNode* cur=head;
        if(cur==nullptr)return false;
        do{
            nodes[cur]=1;
            cur = cur->next;
            if(cur==nullptr)return false;
            if(nodes.find(cur)!=nodes.end())return true;
        }while(true);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */

