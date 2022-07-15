// PROBLEM LINK: https://leetcode.com/problems/house-robber-iii/
// PICK ALTERNATE NODES -> DP ON TREES.


#include <bits/stdc++.h>
#define ll long long int
class Solution {
public:
    // dp[i][0] -> we're not robbing this node.
    // dp[i][1] -> we are going to rob this node.
    
    map<pair<TreeNode *, ll>, ll> dp ;
    void dfs(TreeNode *root){
        if(root->left)
            dfs(root->left) ;
    
        if(root->right)
            dfs(root->right) ;
        
		// if we rob this node -> we can't rob all of it's children
		// if we don't rob this node -> take max of children value -> whether to rob a specific child or not.
        ll child_ans_0 = 0, child_ans_1 = 0 ;
        if(root->left){
            child_ans_0 += max(dp[{root->left, 1}], dp[{root->left, 0}]) ;
            child_ans_1 += dp[{root->left, 0}] ;
        }
        if(root->right){
            child_ans_0 += max(dp[{root->right, 1}], dp[{root->right, 0}]) ;
            child_ans_1 += dp[{root->right, 0}] ;
        }
        dp[{root, 0}] = child_ans_0 ;
        dp[{root, 1}] = root->val + child_ans_1 ;
    }
    
    int rob(TreeNode* root) {
        dfs(root) ;
        
        return max(dp[{root, 1}], dp[{root, 0}]) ;
    }
};










// for general tree

void dfs(ll src, ll par){
    ll sum1=0, sum2=0 ;
    for(auto it : adj[src])
        if(it != par){
            dfs(it, src) ;
            sum1 += dp[it][0] ;
            sum2 += max(dp[it][0], dp[it][1]) ;
        }

    dp[src][0] = sum2 ;
    dp[src][1] = node[src] + sum1 ;
}