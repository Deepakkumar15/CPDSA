#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll  long long int
#define ld  long double
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff  first
#define ss  second
#define pb  push_back

#define min_pair_heap  priority_queue<pi, vpi, greater<pi> >
#define min_heap       priority_queue<ll, vi, greater<ll> >
#define debug(x) cout << (#x) << " -> " << (x) << endl

// Direction arrays
ll dx[4] = {1, 0, 0, -1}; // DLRU
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7

// Modular Exponentiation
ll power(ll x, ll y, ll p){
    ll res=1 ; x%=p ;
    while(y){ if(y&1) res = ((res%p) * (x%p))%p; x = (x*x)%p ; y>>=1 ;}
    return res ;
}

// Modular Multiplication
ll multiply(ll x, ll y, ll p=mod){
    ll res = 0 ; x%=p ;
    while(y){ if(y&1) res = (res%p + x%p) % p ; x = (2 * (x%p)) % p ; y >>= 1 ;}
    return res % p ;
}

// Modular Division
ll divide(ll a, ll b, ll p=mod) {
  if (b % p == 0)return -1;
  return multiply(a % p, power(b, p - 2, p), p);
}

// structure of each node in the m-ary tree
// m -> variable, every node can have any number of childs
class Node{
public:
    char *data ;
    vector<Node *> child ;
};



string serialize(Node *root){
    queue<Node *> q ;
    q.push(root) ;
    string tree = "" ;
    
    while(!q.empty()){
       Node *par = q.front() ;
       q.pop() ;
       tree += par->data ;
    //   for distinguishing between parent and children
       tree += '(' ;
       for(auto it : par->child){
           string child_data = it->data ;
           tree += child_data ;
           tree += ',' ;
           q.push(it) ;
       }
    //   to remove the extra ',' added after the last child
       tree.pop_back() ;
    //   for distinguishing between children and parent
       tree += ')' ;
    }
    
    return tree ;
}

Node* deserialize(string tree){
    
}


signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t = 1 ;
    cin >> t ;
    
    while(t--)
        solve() ;
        
    return 0 ;
}