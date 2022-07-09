// PROBLEM LINK: https://leetcode.com/problems/binary-tree-cameras/submissions/
// BINARY TREE CAMERAS




// DP SOLUTION: (DP ON TREES.)

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

#include <bits/stdc++.h>
#define ll long long int
class Solution {
public:
    map<pair<TreeNode*, pair<ll, ll>>, ll> dp ;
    
    void dfs(TreeNode *root){
        if(root->left)
            dfs(root->left) ;
        if(root->right)
            dfs(root->right) ;
        
        ll child_ans = 1, child_ans2 = 0, child_ans3 = INT_MAX, child_ans4 = INT_MAX;
        if(root->left){
            child_ans += min(dp[{root->left, {0, 1}}], dp[{root->left, {1, 1}}]) ;
            child_ans2 += min(dp[{root->left, {1, 0}}], dp[{root->left, {0, 0}}]) ;
            child_ans3 = dp[{root->left, {1, 0}}] ;
        }
        if(root->right){
            child_ans += min(dp[{root->right, {0, 1}}], dp[{root->right, {1, 1}}]) ;
            child_ans2 += min(dp[{root->right, {1, 0}}], dp[{root->right, {0, 0}}]) ;
            child_ans4 = dp[{root->right, {1, 0}}] ;
        }
        dp[{root, {1, 1}}] = dp[{root, {1, 0}}] = child_ans ;
        dp[{root, {0, 1}}] = child_ans2 ;
        
        if(root->left && root->right){
            child_ans3 = (dp[{root->left, {1, 0}}] + min(dp[{root->right, {1, 0}}], dp[{root->right, {0, 0}}])) ;
            child_ans4 = (dp[{root->right, {1, 0}}] + min(dp[{root->left, {1, 0}}], dp[{root->left, {0, 0}}])) ;
        }
        
        dp[{root, {0, 0}}] = min(child_ans3, child_ans4) ;
    }
    
    int minCameraCover(TreeNode* root) {
        dfs(root) ;
        
        return min(dp[{root, {1, 0}}], dp[{root, {0, 0}}]) ;
    }
};






// POST ORDER TRAVERSAL METHOD.

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

#define ll long long int
class Solution {
public:
    // if the node needs a camera -> -1
    // if the node has a camera installed -> 0
    // if the node is already covered by a camera -> 1
    
    ll cameras = 0 ;
    
    ll dfs(TreeNode *root){
        if(!root){ // null nodes are already covered
            return 1 ;
        }
        
        ll l = dfs(root->left) ;
        ll r = dfs(root->right) ;
        
        if(l==-1 || r==-1){ // if any of the child need camera, then install a camera on root.
            cameras++ ;
            return 0 ;
        }
        
        if(l==0 || r==0){
            return 1 ;
        }
        
        return -1 ;
    }
    
    int minCameraCover(TreeNode* root) {
        ll r = dfs(root) ;
        
        if(r==-1)
            cameras++ ;
        
        return cameras ;
    }
};