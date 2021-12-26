// TAKING INPUT OF A BINARY TREE
// FINDING DIAMETER OF A BINARY TREE
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

int diameter(Node *root){
	if(root == NULL)
		return 0 ;
	int ld = diameter(root->left) ;
	int rd = diameter(root->right) ;
	int lh = height(root->left) ;
	int rh = height(root->right) ;
	int rtd = lh+rh+1 ;
	return max(rtd, max(ld, rd)) ;	
}

signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	int t, val ;
	cin >> t >> val ;
	Node *root = new Node(val) ;
	Node *ptr ;
	string s ;
	int d ;
	while(t--){
		cin >> s ;

		int i=0 ;
		ptr = root ;

		while(s[i] && ptr){
			if(s[i]=='L'){
				if(ptr->left == NULL)
					ptr->left = new Node(0) ;
				ptr = ptr->left ;	
			}
			else{
				if(ptr->right == NULL)
					ptr->right = new Node(0) ;
				ptr = ptr->right ;	
			}
			i++ ;
		}
		cin >> d ;
		ptr->data = d ;
	}

	cout << diameter(root) << endl ;
	return 0 ;
}
