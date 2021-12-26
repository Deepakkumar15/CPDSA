// 0(N) SOLUTION OPTIMIZED CODE
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

pair<int, int> diameter(Node *root){
	if(root == NULL){
		pair<int, int> p ;
		p.first = 0 ;
		p.second = 0 ;
		return p ;
	}

	pair<int, int> ans ;
	pair<int, int> ld = diameter(root->left) ;
	pair<int, int> rd = diameter(root->right) ;
	int lh = ld.first ;
	int rh = rd.first ;
	
	ans.first = max(lh, rh) + 1 ;
	int rtd = lh + rh + 1;
	ans.second = max(rtd, max(ld.second, rd.second)) ;	

	return ans ;
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

	cout << diameter(root).second << endl ;
	return 0 ;
}