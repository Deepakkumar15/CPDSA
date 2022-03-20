// WIDTH OF A TREE
//CF : https://codeforces.com/contest/120/problem/F

#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll  int
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



pi bfs(ll src, ll m, vvi &adj){
    vi dist(m+2, INT_MAX) ;
    queue<ll> q ;
    q.push(src) ;
    dist[src] = 0 ;
    
    while(!q.empty()){
        ll par = q.front() ;
        q.pop() ;
        for(auto child:adj[par]){
            if(dist[child] == INT_MAX){
                dist[child] = dist[par] + 1  ;
                q.push(child) ;
            }
        }
    }
    
    ll rm = -1, idx = src ;
    for(ll i=1; i<=m; i++)
        if(dist[i] > rm){
            rm = dist[i] ;
            idx = i ;
        }
        
    return {idx, rm};
}

void solve(){
    ll n ;
    cin >> n ;
    
    ll ans = 0 ;
    for(ll i=0; i<n; i++){
        ll m;
        cin >> m ;
        vvi adj(m+2) ;
        for(ll i=1; i<m; i++){
            ll u, v ;
            cin >> u >> v ;
            adj[u].pb(v) ;
            adj[v].pb(u) ;
        }
        
        auto it1= bfs(1, m, adj) ;
        auto final_ans = bfs(it1.ff, m, adj) ;
        ans += final_ans.ss ;
    }
    
    cout << ans << "\n" ;
    return ;
}

signed main(){
    // ios_base::sync_with_stdio(false) ;
    // cin.tie(0) ;
    // cout.tie(0) ;
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    ll t=1;
    // cin >> t ;

    while(t--){
        solve() ;
    }

    return 0 ;
}