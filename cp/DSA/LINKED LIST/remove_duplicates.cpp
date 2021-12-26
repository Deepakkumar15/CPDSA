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
    Node *temp = head ;
    while(temp){
        cout << temp->data << " " ;
        temp = temp->link ;
    }
    cout << "\n" ;
}

void remove_duplicates(Node *head){
    unordered_map<int, int> mp ;
    Node *temp = head ;
    Node *prev = NULL ;
    
    while(temp){
        if(!mp[temp->data]){
            mp[temp->data]++ ;
            prev = temp ;
        }
        else
            prev->link = temp->link ;

        temp = temp->link ;
    }
    
}

Node* create(int n){
    int x ;
    cin >> x ;
    Node *head = new Node(x) ;
    Node *temp = head ;
    
    for(int i=1; i<n; i++){
        int x ;
        cin >> x ;
        Node *res = new Node(x) ;
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
    remove_duplicates(head) ;
    print_list(head) ;
    return 0 ;
}