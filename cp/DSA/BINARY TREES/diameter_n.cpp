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
#define ll int

class Solution {
public:
    pair<ll, ll> dfs(TreeNode *root){
        if(!root)
            return {-1, -1} ;
        
        pair<ll, ll> left_child_ans = dfs(root->left) ;
        pair<ll, ll> right_child_ans = dfs(root->right) ;
        
        ll left_height = left_child_ans.first ;
        ll right_height = right_child_ans.first ;
        ll left_diameter = left_child_ans.second ;
        ll right_diameter = right_child_ans.second ;
        
        return {max(left_height, right_height) + 1 , max(left_height + right_height + 2, max(left_diameter, right_diameter))} ;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).second ;
    }
};