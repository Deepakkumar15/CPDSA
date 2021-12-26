// PREORDER TRAVERSAL IN BINARY TREE
// NLR TRAVERSAL
// RECURSIVE VERSION OF PREORDER TRAVERSAL
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

void preorder(Node *root){
    if(root == NULL)
        return ;
    cout << root->data << " " ;
    preorder(root->left) ;
    preorder(root->right) ;
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
    
    preorder(root) ;
    return 0 ;
}



// PREORDER TRAVERSAL IN BINARY TREE
// NLR TRAVERSAL
// ITERATIVE VERSION OF PREORDER TRAVERSAL USING EXPLICIT STACK

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

void preorder(Node *root){
    if(root == NULL)
        return ;
    stack<Node *> s ;
    s.push(root) ;
    
    while(!s.empty()){
        Node *res = s.top() ;
        s.pop() ;
        cout << res->data << " " ;
        
        if(res->right)
            s.push(res->right) ;
        if(res->left)
            s.push(res->left) ;
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
    
    preorder(root) ;
    return 0 ;
}



// MORE OPTIMIZED VERSION
// BY JUST STORING RIGHT CHILD INTO THE STACK
// PREORDER TRAVERSAL IN BINARY TREE
// NLR TRAVERSAL
// ITERATIVE VERSION OF PREORDER TRAVERSAL USING EXPLICIT STACK

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

void preorder(Node *root){
    if(root == NULL)
        return ;
    stack<Node *> s ;
    s.push(root) ;
    Node *curr = root ;
    
    while(!s.empty()){
        if(curr){
            cout << curr->data << " " ;
            if(curr->right)
                s.push(curr->right) ;
            curr = curr->left ;    
        }
        else{
            curr = s.top() ;
            s.pop() ;
        }
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
    
    preorder(root) ;
    return 0 ;
}