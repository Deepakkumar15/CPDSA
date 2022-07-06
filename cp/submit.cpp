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

ll n ;
vi *adj ;
vpi dp(2e5+7) ;

void dfs(ll src, ll par){
    ll mx_val = -1, sec_mx_val = -1;
    for(auto it : adj[src]){
        if(it != par){
            dfs(it, src) ;
            if(dp[it].ff >= mx_val){
                sec_mx_val = mx_val ;
                mx_val = dp[it].ff ;
            }

            else
                sec_mx_val = max(sec_mx_val, dp[it].ff) ;
        }
    }
    
    dp[src] = {mx_val+1, sec_mx_val+1} ;
}


void get_mx_distance(ll src, ll par){
    if(src != 1){
        ll cmp_val = -1 ;
        if(dp[par].ff == dp[src].ff+1){ 
            // that means max. path distance of par exist through this child
            // consider sec. max value of par in this case for comparison.
            cmp_val = dp[par].ss + 1;
        }

        else{
            // that means max. path distance of par exist through another child.
            // consider max. value of par for comparison.
            cmp_val = dp[par].ff + 1 ;            
        }
        
        if(cmp_val >= dp[src].ff){
            dp[src].ss = dp[src].ff ;
            dp[src].ff = cmp_val ;
        }
        
        else
            dp[src].ss = max(dp[src].ss, cmp_val) ;
    }

    for(auto it : adj[src])
        if(it != par)
            get_mx_distance(it, src) ;

} 


void solve(){
    cin >> n ;

    adj = new vi [n+1] ;

    for(ll i=1; i<n; i++){
        ll x, y ;
        cin >> x >> y ;
        adj[x].pb(y) ;
        adj[y].pb(x) ;
    }

    for(ll i=0; i<=n; i++)
        dp[i] = {0, 0} ;
        
    dfs(1, -1) ;
        
    get_mx_distance(1, -1) ;
    
    for(ll i=1; i<=n; i++)
        cout << dp[i].ff << " "  ;
    cout << endl ;
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
