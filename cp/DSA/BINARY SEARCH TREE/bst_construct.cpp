#include <bits/stdc++.h>

using namespace std ;

class Node{
	int data ;
	Node *left, *right ;

	Node(int value){
		data = value ;
		left = right = NULL ;
	}	
};


Node* build(Node *root, int value){
	if(root == NULL){
		Node temp = new Node(value) ;
		return temp ;
	}

	if(value <= root->data)
		root->left = build(root->left, value) ;

	if(value > root->data)
		root->right = build(root->right, value) ;

	return root ;

}

 
 signed main(){
 	vector<int> v(100, 80, 120, 60, 90, 110, 95, 55) ;

 	Node root = new Node(100) ;
 	for(int i=0; i<v.size(); i++){
 		build(root, value) ;
 	}

 	return 0 ;
 }



 							100
 					80              120

 				60



 				0(logn) -> max. height of the tree