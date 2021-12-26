// MIRROR OF BINARY TREE

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

void inorder(Node *root){
    if(root == NULL)
        return ;
    inorder(root->left) ;
    cout << root->data << " " ;
    inorder(root->right) ;
}

Node* mirror(Node *root){
    if(root == NULL)
        return root ;
    swap(root->left, root->right) ;
    
    if(root->left)
        mirror(root->left) ;
    if(root->right)
        mirror(root->right) ;
        
    return root ;
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
    inorder(root) ;
    cout << endl ;
    mirror(root) ;
    
    inorder(root) ;
    return 0 ;
}