#include <bits/stdc++.h>
 
using namespace std ;
 
// template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
#define debug(x) cout << (#x) << " -> " << (x) << endl
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7
 
void solve(){
    // MIN MAX ALGORITHM IN GAME THEORY
    // for maximising the score of A, we have toh minimise the score of B.
    // let score of A = X, B = Y.
    // So, we have toh maximise (X - Y)
    // The trick here is X+Y = sum i.e constant, so put the value of Y in upper equation (Y = sum-X)
    // So, maximise the value 2*X - sum
    ll n, sum=0;
    cin >> n ;
    ll a[n] ;
    for(ll i=0; i<n; i++){
        cin >> a[i] ;
        sum+=a[i] ;
    }
    
    ll dp[n][n][2] = {0} ;
    // dp[i][i][0] = a[i] ;
    // dp[i][i][1] = 0 ;
    
    // while looping we have to ensure the fact that r>=l && r<n always
    for(ll l=n-1; l>=0; l--)
        for(ll r=l; r<n; r++){
            // intializing condition
            if(l==r){
                dp[l][r][0] = a[l] ; // pick the element for 0th player and pass the turn to 1st player
                dp[l][r][1] = 0 ;    // nothing to pick 
            }
            else{
                dp[l][r][0] = max(a[l] + dp[l+1][r][1], a[r] + dp[l][r-1][1]) ;
                dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]) ;
            }
        }
        
    cout << 2*dp[0][n-1][0]-sum << endl ;    
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