// VALIDATE IF THE GIVEN TREE IS BST OR NOT.


#define ll long long int
class Solution {
public:
    bool is_tree_validBST(TreeNode *root, ll min_range_val, ll max_range_val){
        if(!root)
            return true ;
        
        bool is_left_subtree_bst = is_tree_validBST(root->left, min_range_val, root->val) ;
        bool is_right_subtree_bst = is_tree_validBST(root->right, root->val, max_range_val) ;
        
        return (root->val > min_range_val && root->val < max_range_val && 
                is_left_subtree_bst && is_right_subtree_bst) ;
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true ;
            
        return is_tree_validBST(root, -100000000007, 100000000007) ;
        
    }
};






// USING INORDER TRAVERSAL
// INORDER TRAVERSAL OF BST IS ALWAYS SORTED.

class Solution {
public:
    vector<int> preorder ;
    void BST_preorder(TreeNode *root){
        if(!root)
            return ;
        
        BST_preorder(root->left) ;
        preorder.push_back(root->val) ;
        BST_preorder(root->right) ;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true ;
        
        BST_preorder(root) ;
        
        for(int i=1; i<preorder.size(); i++)
            if(preorder[i] <= preorder[i-1])
                return false ;
        
        return true ;
        
    }
};