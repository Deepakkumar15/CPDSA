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
const ll N = 2e5+7 ;
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
vi *adj ;


vector<ll> subtree_size, dp ;
ll tree_size = 1 ;

void dfs(ll src, ll par){
    for(auto it : adj[src]){
        if(it != par){
            dfs(it, src) ;
            // calculate the subtree size of the src node
            subtree_size[src] += subtree_size[it] ;
            // calculate ans for the subtree of src only
            // contribution of the edge between parent and it's one of the childs
            // -> distances_sum of child + subtree_size of the child
            dp[src] += (subtree_size[it] + dp[it]) ;
        }
    }
}

void get_distances_sum(ll src, ll par){
    // already calculated for root -> 0 in dfs fn as we made it the arbitrary node.
    if(src != 1){
        // now re-root the root from parent to it's child(src)
        // child distance_sum = distance_sum(parent) - (remove the edge between parent and this child)
        //                      + (make the child as root i.e change the edge now from child to parent)
        //                      + (distance_sum of child)

        // This is the main equation -> 
        // dp[src] = dp[par] - (subtree_size[src] + dp[src]) + (subtree[par] - subtree[src]) + dp[src] 
        dp[src] = dp[par] + subtree_size[par] - (2*subtree_size[src]) ;

        // change the subtree_size of src -> bcoz it's the root of the tree now.
        subtree_size[src] = tree_size ;
    }
    
    for(auto it : adj[src])
        if(it != par)
            get_distances_sum(it, src) ;
    
}

void solve(){
    cin >> n ;

    adj = new vi [n+1] ;

    for(ll i=2; i<=n; i++){
        ll x, y ;
        cin >> x >> y;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
    }

    for(ll i=0; i<=n; i++){
        subtree_size.push_back(1) ;
        dp.push_back(0) ;
    }

    dfs(1, -1) ;
    tree_size = n ;
    
    get_distances_sum(1, -1) ;
    
    for(ll i=1; i<=n; i++)
        cout << dp[i] << " " ;    
    
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    ll t=1;
    // cin >> t ;

    while(t--)
        solve() ;

    return 0 ;
}
