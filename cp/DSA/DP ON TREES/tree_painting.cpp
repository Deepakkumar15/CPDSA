// CF LINK: https://codeforces.com/contest/1187/problem/E
// VERY NICE PROBLEM BASED ON DP ON TREES


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
vi subtree(2e5+7, 1), dp(2e5+7, 0) ;
ll n ;

void dfs(ll src, ll par){
    for(auto it : adj[src]){
        if(it != par){
            dfs(it, src) ;
            subtree[src] += subtree[it] ;
            dp[src] += dp[it] ;
        }
    }
    
    dp[src] += subtree[src] ;
}

void max_points_gain(ll src, ll par){
    if(src != 1){
        dp[src] = dp[par] + subtree[par] - (2 * subtree[src]) ;
        subtree[src] = n ;
    }
    
    for(auto it : adj[src])
        if(it != par)
            max_points_gain(it, src) ;
}

void solve(){
    cin >> n ;
    
    adj = new vi [n+1] ;
    
    for(ll i=1; i<n; i++){
        ll x, y ;
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    
    
    dfs(1, -1) ;
    
    max_points_gain(1, -1) ;
    
    ll mx_points = 0 ;
    for(ll i=1; i<=n; i++)
        mx_points = max(mx_points, dp[i]) ;
        
    cout << mx_points << endl ;
    
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