/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30204
 *
 * [146] LRU 缓存
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
class LRUCache {
private:
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int cap;
public:
    LRUCache(int capacity) : cap(capacity) {
        map.reserve(capacity);
    }

    int get(int key) {
        auto found = map.find(key);
        if(found != map.end()) {
            items.splice(items.begin(), items, found->second);
            return found->second->second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto found = map.find(key);
        if (found != map.end()) {
            found->second->second = value;
            items.splice(items.begin(), items, found->second);
        }
        else {
            if(map.size() < cap) {
                items.emplace_front(key, value);
                map[key] = items.begin();
            }
            else {
                //需要置换
                auto& backNode = items.back();
                map.erase(backNode.first);
                items.pop_back();
                items.emplace_front(key, value);
                map[key] = items.begin();
            }
        }
    }

};

//总结：对于map的使用，一般不独立使用，而是和另外一个数据结构一起使用，使得查找该结构的时间复杂度为1
//List标准库的使用：splice（pos，list，it）把it迭代器指向的元素不复制的放置到list的pos位置上

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



