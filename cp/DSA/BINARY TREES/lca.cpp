// LCA OF A BINARY TREE


#define ll long long int
class Solution
{
    public:
    vector<Node *> node1_path, node2_path, ancestors ;
    ll fetch_ancestor_for_search_key(struct Node *root, int key){
        if(root == NULL)
            return 0 ;
            
        ll left_child_ans = fetch_ancestor_for_search_key(root->left, key) ;
        ll right_child_ans = fetch_ancestor_for_search_key(root->right, key) ;
        
        
        if(root->data == key || left_child_ans || right_child_ans){
            ancestors.push_back(root) ;
            return key ;
        }
        
        return 0 ;
    }
    
    Node* find_lca_from_node_paths(struct Node* root){
        
        ll i=node1_path.size()-1, j=node2_path.size()-1 ;
        if(i+1==0 || j+1==0){
            return root;
        }
        while(i>=0 && j>=0){
            if(node1_path[i]->data != node2_path[j]->data)
                break ;
            else{
                i--; j-- ;
            }
        }
        
        return node1_path[i+1] ;
    }
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        node1_path.clear() ;
        node2_path.clear() ;
        ancestors.clear() ;
        
        ll node1_root = fetch_ancestor_for_search_key(root, n1) ;
        node1_path = ancestors ;
        ancestors.clear() ;
        
        node1_root = fetch_ancestor_for_search_key(root, n2) ;
        node2_path = ancestors ;
        ancestors.clear() ;
        
        return find_lca_from_node_paths(root); 
        
       
    }
};