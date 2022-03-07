//PRINTING THE SHORTEST PATH FOR WEIGHTED CYCLIC GRAPH
// USING DIJKSTRA ALGORITHM

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
const ll MAX = 1e5+5 ; 
vector<pair<ll, ll>> g[MAX] ;
ll dist[MAX];
ll n, m ;


void dijkstra(ll src){
    vector<ll> prev(n+1);
    vector<ll> ans;
    set<pair<ll, ll>> s ;
    
    for(ll i=1; i<=n; i++)
        dist[i]=LLONG_MAX ;

    dist[src] = 0 ;
    prev[src] = -1;
    s.insert({0, src}) ;
    
    while(!s.empty()){
        auto itr = *(s.begin()) ;
        s.erase(s.begin()) ;
        
        ll p_node = itr.second ;
        ll p_dist = itr.first; 
        
        
        for(auto nbr : g[p_node]){
            ll c_node = nbr.first ;
            ll c_dist = nbr.second ;
            
            if(p_dist + c_dist < dist[c_node]){
                
                if(s.find({dist[c_node], c_node}) != s.end())
                    s.erase({dist[c_node], c_node}) ;
                    
                dist[c_node] = p_dist + c_dist ;
                prev[c_node] = p_node;
                s.insert({dist[c_node], c_node}) ;
            }
        }
    }
    
    if(dist[n]==LLONG_MAX){
        cout << "-1" ;
        return ;
    }    
    
    int cur = n;
    while(cur!=-1){
        ans.push_back(cur) ;
        cur = prev[cur];
    }
    
    for(ll i=ans.size()-1; i>=0; i--)
        cout << ans[i] << " " ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n >> m ;
    for(ll i=1; i<=m; i++){
        ll a, b, w ;
        cin >> a >> b >> w ;
        g[a].push_back({b, w}) ;
        g[b].push_back({a, w}) ;
    }
    
    dijkstra(1) ;
    
    return 0 ;
}



// for printing shortest path:
// vi path ;
// for(path.push_back(dest); dest != src; path.push_back(dest = parent[dest])) ;
// reverse(path.begin(), path.end()) ;