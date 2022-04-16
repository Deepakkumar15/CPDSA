#include <bits/stdc++.h>
 
using namespace std ;
 
// template for ordered_set 
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
#define debug(x) cout << (#x) << " -> " << (x) << endl
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
ll n, m, s;
vpi *adj ;
vi dist(1e5+7, INT_MAX) ;

void dijkstra(vi &src){
    set<pi> s ;
    for(auto it:src){
        dist[it]=0 ; // src nodes
        s.insert({0, it}) ; // inserting all src nodes
    }

    while(!s.empty()){
        auto it = *(s.begin()) ;
        s.erase(s.begin()) ;

        ll node = it.second ;
        ll node_dist = it.first ;

        for(auto nbr : adj[node]){
            ll child = nbr.first ;
            ll child_dist = nbr.second + node_dist ;
            if(child_dist < dist[child]){
                // In set updation is not possible
                // we have to remove the old pair and 
                // insert a new pair instead
                if(s.find({dist[child], child}) != s.end())
                    s.erase({dist[child], child}) ;

                dist[child] = child_dist;
                s.insert({dist[child], child}) ;
            }
        }
    }

    for(ll i=1; i<=n; i++)
        cout << dist[i] << endl ;

    return ;
}   


void solve(){
    cin >> n >> m ;
    adj = new vpi [n+1] ;
    while(m--){
        ll x, y, d ;
        cin >> x >> y >> d ;
        adj[x].push_back({y, d}) ;
        adj[y].push_back({x, d}) ;
    }

    vi src ;
    cin >> s ;
    while(s--){
        ll x ;
        cin >> x ;
        src.push_back(x) ;
    }

    dijkstra(src) ;
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