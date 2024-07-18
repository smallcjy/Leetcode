/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30204
 *
 * [543] 二叉树的直径
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
queue<int> que;
class Solution {
public:
    int max(int a,int b){
        return a>=b?a:b;
    }
    int depth(TreeNode* root){
        if(root==nullptr)return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    int getNodeDiameter(TreeNode* root){
        return depth(root->left)+depth(root->right);
    }
    void getAllDiameter(TreeNode* root){
        if(root==nullptr)return;
        que.push(getNodeDiameter(root));
        getAllDiameter(root->left);
        getAllDiameter(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        getAllDiameter(root);
        while(!que.empty()){
            if(ans<que.front())ans=que.front();
            que.pop();
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

