// find lexicographically smallest shortest path between source and destination nodes if multiple ans exist
// dijkstra with set 

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
    set<pi> s ;
    s.insert({0, src}) ;
    
    while(!s.empty()){
        auto it = *(s.begin());
        s.erase(s.begin()) ;
        ll node = it.second ;
        ll node_dist = it.first ;
        
        for(auto nbr : adj[node]){
            ll v = nbr.first ;
            ll dist = nbr.second ;
            if(node_dist + dist < d[v]){
                if(s.find({d[v], v}) != s.end())
                    s.erase({d[v], v}) ;
                d[v] = node_dist + dist ;
                s.insert({d[v], v}) ;
                parent[v] = node ;
            }
            
            else if(node_dist + dist == d[v])
                parent[v] = node ;
        }
    }
    
    if(d[dest]==INT_MAX){
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
    
    // for(ll i=0; i<N; i++)
    //     adj[i].clear() ;
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