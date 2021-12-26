// LEVEL ORDER TRAVERSAL IN A BINARY TREE
// WITHOUT USING QUEUE

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

void printLevel(Node *root, int level){
    if(root==NULL)
        return ;
    if(level == 1)
        cout << root->data << " " ;
    else if(level > 1){
        printLevel(root->left, level-1) ;   
        printLevel(root->right, level-1) ;   
    }
}

void printLevelOrder(Node *root){
    int h = height(root) ;
    for(int i=1; i<=h; i++)
        printLevel(root, i) ;
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
    printLevelOrder(root) ;
    return 0 ;
}


// USING QUEUE 
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

void LevelOrder(Node *root){
    if(root == NULL)
        return ;
    queue<Node *> q;
    q.push(root) ;
    
    while(!q.empty()){
        Node *res = q.front() ;
        cout << res->data << " ";
        q.pop() ;
        
        if(res->left != NULL)
            q.push(res->left) ;
        if(res->right != NULL)
            q.push(res->right) ;
    }
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
    LevelOrder(root) ;
    return 0 ;
}