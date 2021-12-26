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
ll dx[4] = {1, 0, 0, -1}; // DLRU
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
ll n, m ;
vpi adj[10] ;

void dijkstra(ll src, ll dest){
    vi d(10, INT_MAX) ;
    unordered_map<ll, ll> parent ;
    d[src]=0 ;
    priority_queue<pi, vpi, greater<pi>> pq ;
    pq.push({0, src}) ;
    
    while(!pq.empty()){
        auto it = pq.top() ;
        pq.pop() ;
        ll node = it.second ;
        ll node_dist = it.first ;
        if(node_dist != d[node]) // handled/old/processed pairs
            continue ;
        
        for(auto nbr : adj[node]) {
            ll v = nbr.first ;
            ll dist = nbr.second ;
            if((node_dist + dist) < d[v]){
                d[v] = node_dist + dist ;
                pq.push({d[v], v}) ;
                parent[v] = node ;
            } else if(node_dist + dist == d[v]) { // for finding the lexicographically smallest shortest path
                parent[v] = node;
            }
        }
    }
    
    if(d[dest] == INT_MAX){
        cout << -1 << "\n" ;
        return ;
    }
 
    if(dest == src){
        cout << src << "\n" ;
        return ;
    }
 
    vi path ;
    for(path.push_back(dest); dest != src; path.push_back(dest = parent[dest])) ;
    reverse(path.begin(), path.end()) ;
    for(auto it:path)
        cout << it << " "  ;
    cout << "\n" ;
    
    return ;
}

void solve(){
    cin >> n >> m ;
    for(ll i=0; i<m; i++){
        ll x, y, w ;
        cin >> x >> y >> w ;
        adj[x].push_back({y, w}) ;
    }
    
    dijkstra(1, 8) ;
    
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
