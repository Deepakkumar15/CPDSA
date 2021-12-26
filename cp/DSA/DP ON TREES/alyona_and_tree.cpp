#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define vvi vector<vi>
#define debug(x) cout << (#x) << " -> " << (x) << endl

// Direction arrays
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
vpi adj[N] ;
vi a(N, 0) ;
vi child(N, 1) ;
ll ans=0 ;

void dfs(ll src, ll par){
    for(auto it : adj[src])
        if(it.first != par){
            dfs(it.first, src) ;
            child[src] += child[it.first] ;    
        }
        
    return ;    
}

void dfs1(ll src, ll par, ll dist){
    if(dist > a[src]){
        ans += child[src] ; // remove the whole subtree
        return ;
    }
    for(auto it:adj[src])
        if(it.first != par)
            dfs1(it.first, src, max(dist+it.second, it.second)) ;
        
    return ;
}

void solve(){
    ll n ;
    cin >> n ;
    // 1-based indexing 
    for(ll i=1; i<=n; i++)
        cin >> a[i] ;
        
    for(ll i=1; i<=n-1; i++){
        ll x, w ;
        cin >> x >> w ;
        adj[i+1].push_back({x, w}) ;
        adj[x].push_back({i+1, w}) ;
    }
    
    // dfs to find the size of subtree
    dfs(1, -1) ;
    
    // counting the number of nodes to be removed to make the tree sad free
    dfs1(1, -1, 0) ;
    
    cout << ans << endl ;
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