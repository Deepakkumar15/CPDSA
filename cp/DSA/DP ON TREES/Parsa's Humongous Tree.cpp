// CODEFORCES SOLUTION 
// Parsa's Humongous Tree 

#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
const ll N = 1e5+7 ;
vpi ranges(N), dp(N) ;
vi adj[N] ;

void dfs(ll src, ll par){
    dp[src].first = dp[src].second = 0 ;
    for(auto it : adj[src]){
        if(it==par)
            continue ;
        dfs(it, src) ;
        dp[src].first += max(abs(ranges[src].first - ranges[it].first)+dp[it].first, abs(ranges[src].first - ranges[it].second)+dp[it].second) ;
        dp[src].second += max(abs(ranges[src].second - ranges[it].first)+dp[it].first, abs(ranges[src].second - ranges[it].second)+dp[it].second) ;
    }
        
    return ;    
}

void solve(){
    ll n ;
    cin >> n ;
    for(ll i=1; i<=n; i++){
        ll li, ri ;
        cin >> li >> ri ;
        ranges[i] = {li, ri} ;
    }
     
    ll m = n-1 ;
    while(m--){
        ll u, v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1) ;
    cout << max(dp[1].first, dp[1].second) << "\n" ;
    for(ll i=0; i<N; i++)
        adj[i].clear() ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t ;
    cin >> t ;
    while(t--)  
        solve() ;
    return 0 ;
}


// USING VISITED ARRAY INSTEAD OF PARENT 
#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
const ll N = 1e5+7 ;
vpi ranges(N), dp(N) ;
vi adj[N] ;
vb visited(N, false) ;

void dfs(ll src){
    visited[src]=true ;
    dp[src].first = dp[src].second = 0 ;
    
    for(auto it : adj[src])
        if(!visited[it]){
            dfs(it) ;
            dp[src].first += max(abs(ranges[src].first - ranges[it].first)+dp[it].first, abs(ranges[src].first - ranges[it].second)+dp[it].second) ;
            dp[src].second += max(abs(ranges[src].second - ranges[it].first)+dp[it].first, abs(ranges[src].second - ranges[it].second)+dp[it].second) ;
        }
        
    return ;    
}

void solve(){
    ll n ;
    cin >> n ;
    for(ll i=1; i<=n; i++){
        ll li, ri ;
        cin >> li >> ri ;
        ranges[i] = {li, ri} ;
    }
     
    ll m = n-1 ;
    while(m--){
        ll u, v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1) ;
    cout << max(dp[1].first, dp[1].second) << "\n" ;
    
    for(ll i=0; i<N; i++){
        adj[i].clear() ;
        visited[i]=false ;
    }
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t ;
    cin >> t ;
    while(t--)  
        solve() ;
    return 0 ;
}