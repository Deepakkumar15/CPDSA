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










// #include <bits/stdc++.h>
 
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

ll tc=1 ;
vi *adj ;
vi tour, start(1e3+7, 0), match(1e3+7, 0);
ll idx = 1 ;

void dfs(ll src, ll par){
    match[src] = idx++ ;
    start[match[src]] = tour.size() ;
    tour.pb(match[src]);
    for(auto it:adj[src])
        if(it != par){
            dfs(it, src) ;
            tour.pb(match[src]);
        }
    
    return ;
}

void solve(){
    ll n ;
    cin >> n ;
    adj = new vi [n+1] ;
    for(ll i=1; i<=n; i++){
        ll m ;
        cin >> m ;
        while(m--){
            ll x ;
            cin >> x ;
            adj[i].pb(x) ;
            adj[x].pb(i) ;
        }
    }
    
    // ll q ;
    // cin >> q ;
    // cout << "Case " << tc << ":\n" ;
    // while(q--){
    //     ll u, v ;
    //     cin >> u >> v ;
    //     if(start[u] > start[v])
    //         swap(u, v) ;
        
    //     cout << ans << endl ;
    // }
    tour.pb(0) ;
    dfs(1, -1) ;
    for(ll i=1; i<2*n; i++)
        cout << tour[i] << " "  ;
    cout << endl ;
    
    for(ll i=1; i<=n; i++)
        cout << start[match[i]] << " " ;
    cout << endl ;
    
    for(ll i=1; i<=n; i++)
        cout << match[i] << " "  ;
    cout << endl ;
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
