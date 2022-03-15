// FIND THE SHORTEST CYCLE IN A GRAPH USING BFS

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
ll dx[4] = {1, 0, 0, -1}; // DLRU
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


vi *adj ;
ll n, m ;
ll tc=1 ;

ll bfs(ll src){
    ll ans = INT_MAX ;
    vi dist(n+1, INT_MAX) ;
    queue<pi> q ;
    q.push({src, -1}) ;
    dist[src] = 0 ;
    
    while(!q.empty()){
        auto res = q.front() ;
        q.pop() ;
        for(auto it : adj[res.ff]){
            if(dist[it] == INT_MAX){
                dist[it] = dist[res.ff] + 1 ;
                q.push({it, res.ff}) ;
            }
            else if(dist[it] != INT_MAX && it != res.ss){
                ans = min(ans, dist[it]+dist[res.ff]+1) ;
            }
        }
    }
    
    return ans ;
}


void solve(){
    cin >> n >> m;
    adj = new vi [n+1] ;

    for(ll i=1; i<=m; i++){
        ll x, y ;
        cin >> x >> y ;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
    }
    
    ll ans = INT_MAX ;
    for(ll i=0; i<n; i++){
        ans = min(ans, bfs(i)) ;    
    }
    
    cout << "Case " << tc++ << ": "  ;
    if(ans == INT_MAX)
        cout << "impossible\n" ;
    else    
        cout << ans << "\n" ;
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
