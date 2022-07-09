// PROBLEM LINK: - https://www.spoj.com/problems/HOLI/
// PIGEON HOLE PRINCIPLE OR TREE CENTROIDS CONCEPT


#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<ll> s ; *s.find_by_order(k) -> returns kth indexed element starting from 0
// s.order_of_key(k) -> return no. of element strictly less than k
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
const ll N = 3e5+7 ;
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

ll n ;
vpi *adj;
vi subtree_size(1e5+7, 1) ;
ll edge_contribution = 0, tc = 0 ;

void dfs(ll src, ll par){
    for(auto it : adj[src]){
        if(it.ff != par){
            dfs(it.ff, src) ;
            // add the subtree child size into par
            subtree_size[src] += subtree_size[it.ff] ;
            // calculate this edge contribution
            edge_contribution += (2*(min(n-subtree_size[it.ff], subtree_size[it.ff]))*(it.ss)) ; 
        }
    }
}

void solve(){
    cin >> n ;
    
    adj = new vpi [n+1] ;
    
    edge_contribution = 0 ;
    for(ll i=0; i<=n; i++){
        adj[i].clear() ;
        subtree_size[i] = 1 ;
    }

    for(ll i=1; i<n; i++){
        ll x, y, w ;
        cin >> x >> y >> w ;
        adj[x].push_back({y, w}) ;
        adj[y].push_back({x, w}) ;
    }

    dfs(1, -1) ;

    cout << "Case #" << ++tc << ": " << edge_contribution << "\n" ;
    
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    ll t=1;
    cin >> t ;

    while(t--)
        solve() ;

    return 0 ;
}
