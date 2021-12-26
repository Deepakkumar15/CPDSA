#include <bits/stdc++.h>

using namespace std ;

class Node{
public:
    int data ;
    Node *link ;
    
    Node(int val){
        data = val ;
        link = NULL ;
    }
};

void print_list(Node *head){
    if(!head)
        return ;
    Node *temp = head ;
    while(temp){
        cout << temp->data << " ";
        temp = temp->link ;
    }
}

Node* first(Node *head){
    if(!head || !head->link)
        return head ;
    Node *curr = head, *prev = NULL ;
    while(curr->link){
        prev = curr ;
        curr = curr->link ;
    }
    curr->link = head;
    prev->link = NULL ;
    head = curr ;
    
    return head ;
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
    cout << endl ;
    
    head = first(head) ;
    print_list(head) ;
    
    return 0 ;
}