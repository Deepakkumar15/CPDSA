// REVERSING A LINKED LIST
// ITERATIVE METHOD
// USING THREE POINTER

#include <bits/stdc++.h>

using namespace std ;

class Node{
public:
    int data ;
    Node *link ;
    Node(int val){
        data = val ;
        link = nullptr ;
    }
    
};

void reverse_print(Node *head){
    Node *temp = head ;
    if(temp == NULL)
        return ;
    reverse_print(temp->link) ;
    cout << temp->data << " " ;
}

void print_list(Node *head){
    Node *temp = head ;
    while(temp){
        cout << temp->data << " " ;
        temp = temp->link ;
    }
}

Node* reverse(Node *head){
    Node *curr = head ;
    Node *prev = NULL, *next = NULL ;
    while(curr){
        next = curr->link ;
        curr->link = prev ;
        prev = curr ;
        curr = next ;
        
    }
    
    return head = prev ;
}

Node* create(int n){
    int x ;
    cin >> x ;
    Node *head = new Node(x) ;
    Node *temp = head ;
    
    for(int i=1; i<n; i++){
        int y ;
        cin >> y ;
        Node *res = new Node(y) ;
        temp->link = res ;
        temp = temp->link ;
    }
    
    return head ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int n ;
    cin >> n ;
    Node *head = create(n) ;
    print_list(head) ;
    cout << endl; 
    reverse_print(head) ;
    cout << endl; 
    head = reverse(head) ;
    print_list(head) ;
    return 0 ;
}
