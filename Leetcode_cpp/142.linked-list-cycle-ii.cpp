/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30204
 *
 * [142] 环形链表 II
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

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        do{
            if(fast->next == nullptr|| fast->next->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        fast = head;
        while(fast != slow){    
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
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

