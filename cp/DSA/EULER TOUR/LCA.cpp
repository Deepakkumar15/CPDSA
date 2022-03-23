// FIND LCA OF A GIVEN TREE USING EULER TOUR
// 0(N) SOLUTION USING EULER TOUR


#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set s ; *s.find_by_order(k) -> returns kth indexed element starting from 0
// s.order_of_key(k) -> return no. of element strictly less than k
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
vi tour, start(1e3+7, 0);
map<ll, ll> old_match, new_match;
ll idx = 1 ;

void dfs(ll src, ll par){
    old_match[src] = idx;
    new_match[idx++] = src ;
    start[old_match[src]] = tour.size() ;
    tour.pb(old_match[src]);
    for(auto it:adj[src])
        if(it != par){
            dfs(it, src) ;
            tour.pb(old_match[src]);
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
    // EULER TREE AFTER REASSIGNING THE NODE NAMES/INDEX
    tour.pb(0) ;
    dfs(1, -1) ;
       
    ll q ;
    cin >> q ;
    cout << "Case " << tc++ << ":\n" ;
    while(q--){
        ll u, v ;
        cin >> u >> v ;
        u = old_match[u] ;
        v = old_match[v] ;
        
        if(start[u] > start[v])
            swap(u, v) ;

        ll mn = INT_MAX;
        for(ll i=start[u]; i<=start[v]; i++)
            mn = min(mn, tour[i]) ;
        // debug(mn) ;
        cout << new_match[mn] << endl ;
    }
    
    
    // clear the global variables as well
    for(ll i=0; i<=n; i++)
        adj[i].clear() ;
    tour.clear() ;
    old_match.clear(); new_match.clear() ;
    idx=1 ;
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








// LCA IN 0(1)

// FIND LCA OF A GIVEN TREE USING EULER TOUR
// 0(N) SOLUTION USING EULER TOUR


#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set s ; *s.find_by_order(k) -> returns kth indexed element starting from 0
// s.order_of_key(k) -> return no. of element strictly less than k
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
const ll N = 2e3+7 ;
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
vi tour, start(1e3+7, 0);
map<ll, ll> old_match, new_match;
ll idx = 1 ;
ll table[N][31] ;

void build(ll n){
    for(ll j=1; j<=30; j++)
        for(ll i=0; i+(1 << j)<=n; i++)
            table[i][j] = min(table[i][j-1], table[i+(1 << j-1)][j-1]) ;
}

ll query(ll l, ll r){
    ll len = r-l+1 ;
    ll j = log2(len) ; // find the power of 2 such that 1 << j <= len

    return min(table[l][j], table[r-(1<<j)+1][j]) ;
}

void dfs(ll src, ll par){
    old_match[src] = idx;
    new_match[idx++] = src ;
    start[old_match[src]] = tour.size() ;
    tour.pb(old_match[src]);
    for(auto it:adj[src])
        if(it != par){
            dfs(it, src) ;
            tour.pb(old_match[src]);
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
    // EULER TREE AFTER REASSIGNING THE NODE NAMES/INDEX
    tour.pb(0) ;
    dfs(1, -1) ;
    
    for(ll i=1; i<2*n; i++)
        table[i][0] = tour[i] ;
        
    build(2*n);
    ll q ;
    cin >> q ;
    cout << "Case " << tc++ << ":\n" ;
    while(q--){
        ll u, v ;
        cin >> u >> v ;
        u = old_match[u] ;
        v = old_match[v] ;
        
        if(start[u] > start[v])
            swap(u, v) ;

        ll mn = query(start[u], start[v]) ;
        cout << new_match[mn] << endl ;https://codeforces.com/contest/1657/problem/D
    }
    
    
    // clear the global variables as well
    for(ll i=0; i<=n; i++)
        adj[i].clear() ;
    tour.clear() ;
    old_match.clear(); new_match.clear() ;
    idx=1 ;
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