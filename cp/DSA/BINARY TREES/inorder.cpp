// INORDER TRAVERSAL IN BINARY TREE
// LNR TRAVERSAL
// RECURSIVE VERSION OF INORDER TRAVERSAL

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

void inorder(Node *root){
    if(root == NULL)
        return ;
    
    inorder(root->left) ;
    cout << root->data << " " ;
    inorder(root->right) ;
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
    root->right->left = new Node(2);
    
    inorder(root) ;
    return 0 ;
}



// INORDER TRAVERSAL IN BINARY TREE
// LNR TRAVERSAL
// ITERATIVE VERSION OF INORDER TRAVERSAL USING EXPLICIT STACK

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

void inorder(Node *root){
    if(root == NULL)
        return ;
    stack<Node *> s ;
    Node *curr = root ;
    
    while(!s.empty() || curr){
        while(curr){
            s.push(curr) ;
            curr = curr->left ;
        }
        
        curr = s.top() ;
        s.pop() ;
        cout << curr->data << " " ;
        curr = curr->right ;
        
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
    root->right->left = new Node(2);
    
    inorder(root) ;
    return 0 ;
}
