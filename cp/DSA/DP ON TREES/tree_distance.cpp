// PROBLEM LINK: https://codeforces.com/contest/161/problem/D


#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<ll> s ; *s.find_by_order(k) -> returns kth indexed element starting from 0
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
const ll N = 3e5+7 ;
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

ll n, k ;
vi *adj, *dp ;

void dfs(ll src, ll par){
    dp[src][0] = 1 ;
    for(auto it : adj[src])
        if(it != par){
            dfs(it, src) ;
            for(ll i=1; i<=500; i++)
                dp[src][i] += dp[it][i-1] ;
        }
}

void calculate_distance(ll src, ll par){
    if(src != 1){
        vi pa = dp[par] ;
        for(ll i=1; i<=500; i++)
            pa[i] -= dp[src][i-1] ;
        for(ll i=1; i<=500; i++)
            dp[src][i] += pa[i-1] ;
    }
    
    for(auto it : adj[src])
        if(it != par)
            calculate_distance(it, src) ;
}

void solve(){
    cin >> n >> k ;
    adj = new vi [n+1] ;
    dp = new vi [n+1] ;
    
    for(ll i=1; i<n; i++){
        ll x, y ;
        cin >> x >> y ;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
    }
    
    for(ll i=0; i<=n; i++)
        for(ll j=0; j<=500; j++)
            dp[i].pb(0) ;
    
    dfs(1, -1) ;
    
    calculate_distance(1, -1) ;
    
    ll total_pairs = 0 ;
    for(ll i=1; i<=n; i++){
        total_pairs += dp[i][k] ;
    }
        
    cout << total_pairs/2 << endl ;
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