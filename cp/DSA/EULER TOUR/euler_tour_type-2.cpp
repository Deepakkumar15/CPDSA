// TYPE-2 OF EULER TOUR OF A TREE OR TREE FLATTENING 
// EULER TOUR OF TYPE-2 (USED FOR MOST OF TIME)
// POWERFUL CONCEPT (EULER TOUR + RANGE QUERIES)

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
ll st[N+1], ed[N+1], time_=1 ; // FOR STORING STARTING AND ENDING TIME OF A NODE
bool visited[N] = {false} ;

ll n, m;

// FOR MAKING START AND END ARRAY FOR EULER TOUR OF TYPE-2
// WE CAN ALSO STORE REQUIRED DATA ACC. TO QUESTION DEMAND
void dfs(ll src){
    visited[src]=true ;
    st[src] = time_++ ; 
    for(auto it : adj[src])
        if(!visited[it])
            dfs(it) ;
    
    ed[src] = time_++ ;
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
    
    dfs(1) ;
    // MAKING EULER TOUR ARRAY FROM STARTING AND ENDING ARRAY
    for(ll i=1; i<=n; i++){
        t[st[i]]=i ;
        t[ed[i]]=i ;
    }
    
    for(ll i=1; i<=n; i++)
        cout << st[i] << " " ;
    cout << endl ;
    
    for(ll i=1; i<=n; i++)
        cout << ed[i] << " " ;
    cout << endl ;
    
    for(ll i=1; i<=2*n; i++)
        cout << t[i] << " " ;
    cout << endl ;
    return 0 ;
}