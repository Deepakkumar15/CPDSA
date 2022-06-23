//Given a binary tree, 
//find the max sum of nodes with the condition that if you pick a node,
// you can’t choose its immediate child.


class Node{
    ll data;
    Node *left, *right ;
    
    Node(ll val){
        data = val ;
        left = right = NULL ;
    }
}

ll mx_sum_value = 0, tree_sum = 0 ;

ll dfs(Node *root){
    if(!root)
        return 0 ;
        
    ll left_subtree_sum = dfs(root->left, root->data) ;
    ll right_subtree_sum = dfs(root->right, root->data) ;
    
    ll tree_sum = left_subtree_sum + right_subtree_sum + root->data ;
    
    return tree_sum;
}

void dfs1(Node *root, ll parent){
    if(!root)
        return ;
        
        
    dfs1(root->left, root->data) ;
    dfs1(root->right, root->data) ;
    
    ll value_to_remove = parent ;
    if(root->left)
        value_to_remove += root->left->data ;
    if(root->right)
        value_to_remove += root->right->data ;
    
    mx_sum_value = max(mx_sum_value, max(value_to_remove, tree_sum-value_to_remove)) ;
    
    return ;
}

ll find_max_tree_sum(Node *root){
    tree_sum = dfs(root) ;
    
    dfs1(Node *root, 0) ;

    return mx_sum_value ;
}