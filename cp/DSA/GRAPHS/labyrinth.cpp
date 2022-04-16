// CSES LINK: https://cses.fi/problemset/task/1193/

#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ll  long long int
#define ld  long double
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff  first
#define ss  second
#define pb  push_back
 
#define min_pair_heap  priority_queue<pi, vpi, greater<pi> >
#define min_heap       priority_queue<ll, vi, greater<ll> >
#define debug(x) cout << (#x) << " -> " << (x) << endl
 
// Direction arrays
ll dx[4] = {1, 0, 0, -1}; //DLRU
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
 
// Modular Exponentiation
ll power(ll x, ll y, ll p){
    ll res=1 ; x%=p ;
    while(y){ if(y&1) res = ((res%p) * (x%p))%p; x = (x*x)%p ; y>>=1 ;}
    return res ;
}
 
// Modular Multiplication
ll multiply(ll x, ll y, ll p=mod){
    ll res = 0 ; x%=p ;
    while(y){ if(y&1) res = (res%p + x%p) % p ; x = (2 * (x%p)) % p ; y >>= 1 ;}
    return res % p ;
}
 
// Modular Division
ll divide(ll a, ll b, ll p=mod) {
  if (b % p == 0)return -1;
  return multiply(a % p, power(b, p - 2, p), p);
}
 
ll n, m;
vs adj ;
// string temp = "DLRU"; 
string path="" ;
bool bfs(pi src, pi dest){
    vi parent(1e6+7, -1) ;
    queue<pi> q ;
    q.push(src) ;
    adj[src.ff][src.ss] = '#' ;
    parent[src.ff*m+src.ss] = src.ff*m+src.ss ;
    
    while(!q.empty()){
        auto par = q.front() ;
        q.pop() ;
        for(ll i=0; i<4; i++){
            ll x = par.ff + dx[i] ;
            ll y = par.ss + dy[i] ;
            if(x < 0 || x >= n || y < 0 || y >= m || adj[x][y] == '#')
                continue ;
            adj[x][y] = '#' ;
            pi child = {x, y} ;
            q.push(child) ;
            parent[x*m+y] = par.ff*m+par.ss ;
        }
    }
    
    if(parent[dest.ff*m+dest.ss] == -1)
        return false ;
    
    ll s = src.ff*m+src.ss, d = dest.ff*m+dest.ss;
    while(d != s){
        ll new_d = parent[d] ;
        if(d-new_d == m) path.pb('D') ;
        if(d-new_d == -m) path.pb('U') ;
        if(d-new_d == -1) path.pb('L') ;
        if(d-new_d == 1) path.pb('R') ;
        d = new_d ;
    }
    
    reverse(path.begin(), path.end()) ;
    return true;
}
 
void solve(){
    cin >> n >> m;
    for(ll i=0; i<n; i++){
        string s ;
        cin >> s ;
        adj.pb(s) ;
    }
    
    pi start, dest ;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++){
            if(adj[i][j] == 'A')
                start = {i, j} ;
            if(adj[i][j] == 'B')
                dest = {i, j} ;
        }
        
    bool flag = bfs(start, dest) ;
    if(!flag){
        cout << "NO" ;
        return ;
    }
    
    cout << "YES" << endl << path.size() << endl << path ;
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