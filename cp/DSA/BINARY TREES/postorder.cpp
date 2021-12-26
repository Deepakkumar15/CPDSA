// POSTORDER TRAVERSAL IN BINARY TREE
// LRN TRAVERSAL
// RECURSIVE VERSION OF PSOTORDER TRAVERSAL

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

void postorder(Node *root){
    if(root == NULL)
        return ;
    
    postorder(root->left) ;
    postorder(root->right) ;
    cout << root->data << " " ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    Node *root = new Node(1) ;
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(11);
    
    postorder(root) ;
    return 0 ;
}



// POSTORDER TRAVERSAL IN BINARY TREE
// LRN TRAVERSAL
// ITERATIVE VERSION OF POSTORDER TRAVERSAL USING EXPLICIT STACK


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

void postorder(Node *root){
    if(root == NULL)
        return ;
    stack<Node *> s ;
    s.push(root) ;
    
    stack<int> ans ;
    
    while(!s.empty()){
        Node *curr = s.top() ;
        s.pop() ;
        ans.push(curr->data) ;
        
        if(curr->left)
            s.push(curr->left) ;
        if(curr->right)
            s.push(curr->right) ;
    }
    
    while(!ans.empty()){
        cout << ans.top() << " " ;
        ans.pop() ;
    }
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    Node *root = new Node(1) ;
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(11);
    
    postorder(root) ;
    return 0 ;
}
