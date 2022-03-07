// LONGEST PATH IN THE TREE 
// SPOJ
// DO DOUBLE BFS

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
vector<ll> *l ;
ll n ;
ll max_dist = -INF, index = src

void bfs(ll src){
    bool visited[n+1]={false};
    queue<ll> q ;
    q.push(src) ;
    visited[src]=true ;
    ll dist[n+1] ;
    dist[src]=0 ;
    
    while(!q.empty()){
        ll node = q.front() ;
        q.pop() ;
        
        for(auto it:l[node]){
            if(!visited[it]){
                visited[it]=true ;
                q.push(it) ;
                dist[it]=dist[node]+1 ;
            }
        }
    }
    
    
    for(ll i=1; i<=n; i++){
        if(dist[i] > max_dist){
            max_dist = dist[i] ;
            index = i ;
        }
    } 
        
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n ;
    l = new vector<ll> [n+1] ;
    for(ll i=1; i<n; i++){
        ll x, y ;
        cin >> x >> y ;
        l[x].push_back(y) ;
        l[y].push_back(x) ;
    }
    
    bfs(1) ;
    bfs(ri) ;
    cout << rm  ;
    return 0 ;
}