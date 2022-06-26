// check if two binary trees are same or not


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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p && q) || (!q && p))
            return false ;
        if(!p && !q)
            return true ;
        
        bool check_left_subtree = isSameTree(p->left, q->left) ;
        bool check_right_subtree = isSameTree(p->right, q->right) ;
        
        return (p->val == q->val && check_left_subtree && check_right_subtree) ;
    }
};