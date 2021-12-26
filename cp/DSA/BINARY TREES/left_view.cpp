//LEFT VIEW OF A BINARY TREE

vector<int> leftView(Node *root){
    vector<int> ans ;
    if(root == nullptr)
        return ans ;
    queue<Node *> q ;
    q.push(root) ;
    
    while(!q.empty()){
        int res = q.size() ;
        vector<int> level ;
        while(res--){
            Node *curr = q.front() ;
            q.pop() ;
            level.push_back(curr->data) ;
            
            if(curr->left)
                q.push(curr->left) ;
            if(curr->right)
                q.push(curr->right) ;
        }
        ans.push_back(level[0]) ;
    }
    
    return ans ;
}