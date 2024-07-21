/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30204
 *
 * [138] 随机链表的复制
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // 检查原链表是否为空

        unordered_map<Node*, Node*> map; // 使用原节点的指针作为键
        Node* cur = head;
        // 创建一个新的头节点
        Node* dummy = new Node(0);
        Node* prev = dummy;

        // 第一遍遍历，复制节点和next指针
        while (cur) {
            Node* copied = new Node(cur->val);
            prev->next = copied;
            map[cur] = copied; // 建立原节点和新节点的映射
            prev = copied;
            cur = cur->next;
        }

        // 第二遍遍历，复制random指针
        cur = head;
        Node* copyCur = dummy->next;
        while (cur) {
            if (cur->random) {
                copyCur->random = map[cur->random]; // 通过映射找到对应的新节点
            }
            cur = cur->next;
            copyCur = copyCur->next;
        }

        Node* res = dummy->next;
        delete dummy; // 删除哑节点
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */

