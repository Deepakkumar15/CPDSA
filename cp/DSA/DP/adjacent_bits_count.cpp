// ADJACENT BIT COUNTS SPOJ SOLUTION

#include <bits/stdc++.h>
 
using namespace std ;
 
// Template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define vvi vector<vi>
#define debug(x) cout << (#x) << " -> " << (x) << endl

// Direction arrays
ll dx[4] = {1, 0, 0, -1}; // DLRU
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7

void solve(){
    ll tc, n, k ;
    cin >> tc >> n >> k ;
    
    ll dp[n+1][k+1][2] ;
    for(ll i=0; i<=n; i++)
        for(ll j=0; j<=k; j++)
            dp[i][j][0] = dp[i][j][1] = 0 ;
    
    dp[1][0][0] = dp[1][0][1] = 1 ;
    for(ll i=2; i<=n; i++){
        dp[i][0][0] += (dp[i-1][0][0] + dp[i-1][0][1]) ;
        dp[i][0][1] += dp[i-1][0][0] ;
    }
    
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=k; j++){
            dp[i][j][0] += (dp[i-1][j][0] + dp[i-1][j][1]) ;
            dp[i][j][1] += (dp[i-1][j][0] + dp[i-1][j-1][1]) ;
        }

    cout << tc << " " << dp[n][k][0] + dp[n][k][1] << endl ;    
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