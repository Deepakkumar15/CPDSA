#include <bits/stdc++.h>

using namespace std ;

class Node{
public:
    int data ;
    Node *left ;
    Node *right ;
    
    Node(int val){
        data = val ;
        left = right = NULL ;
    }
};

int height(Node *root){
    if(root==NULL)
        return 0 ;
    int lheight = height(root->left) ;    
    int rheight = height(root->right) ;    
    
    if(lheight > rheight)
        return lheight+1 ;
    return rheight+1 ;    
}

vector<int> reverseLevelOrder(Node *root){
   vector<int> res ;
    if(root == NULL)
        return res;
    queue<Node*> q ;
    q.push(root) ;
    
    while(!q.empty()){
        Node *temp = q.front() ;
        res.insert(res.begin(), temp->data) ;
        q.pop() ;
        
        if(temp->right!=NULL)
            q.push(temp->right) ;
        if(temp->left!=NULL)
            q.push(temp->left) ;
        
    }

    return res ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0);
    
    Node *root = new Node(1) ;
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    
    cout << height(root) << endl ;
    vector<int> ans = reverseLevelOrder(root) ;
    for(auto it:ans)
        cout << it << " " ;
    cout << "\n" ;
    return 0 ;
}