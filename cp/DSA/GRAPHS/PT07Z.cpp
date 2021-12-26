// LONGEST PATH IN THE TREE 
// SPOJ
// DO DOUBLE BFS

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int
vector<ll> *l ;
ll n ;
ll rm=0, ri=0 ;

void bfs(ll src){
    bool visited[n+1]={false};
    queue<ll> q ;
    q.push(src) ;
    visited[src]=true ;
    ll level[n+1] ;
    level[src]=0 ;
    
    while(!q.empty()){
        ll node = q.front() ;
        q.pop() ;
        
        for(auto it:l[node]){
            if(!visited[it]){
                visited[it]=true ;
                q.push(it) ;
                level[it]=level[node]+1 ;
            }
        }
    }
    
    for(ll i=1; i<=n; i++){
            rm = max(rm, level[i]) ;
            if(rm==level[i]) 
                ri=i;
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