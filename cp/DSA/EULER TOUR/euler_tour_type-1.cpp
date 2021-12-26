// TYPE-1 OF EULER TOUR OF A TREE OR TREE FLATTENING 
// EULER TOUR OF TYPE-1 (USED FOR FINDING LCA IN O(1))

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
vi adj[N] ; // FOR MAKING TREE
ll t[2*N+1] ; // FOR EULER TOUR OF TREE
bool visited[N]={false} ;

ll n, m;

// FOR JUST MAKING EULER TOUR ARRAY OF TYPE 1
void dfs(ll src, ll &idx){
    visited[src]=true ;
    t[idx++] = src ; 
    for(auto it : adj[src])
        if(!visited[it]){
            dfs(it, idx) ;
            t[idx++] = src ; 
        }
    
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    cin >> n >> m ;
    while(m--){
        ll a, b;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    ll idx=1 ;
    dfs(1, idx) ;
    
    for(ll i=1; i<2*n; i++)
        cout << t[i] << " " ;
    cout << endl ;
    return 0 ;
}