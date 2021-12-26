// VANYA AND GCD ARRAY HACKEREARTH 

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
    ll n ;
    cin >> n ;
    vi a(n) ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    
    ll dp[n][101] ;
    for(ll i=0; i<n; i++)
        for(ll j=0; j<=100; j++)
            dp[i][j]=0 ;
     
    dp[0][a[0]]=1 ;
    
    for(ll i=1; i<n; i++){
        for(ll j=i-1; j>=0; j--){
            if(a[j] < a[i])
                for(ll k=1; k<=100; k++)
                    dp[i][__gcd(k, a[i])] = (dp[i][__gcd(k, a[i])]%mod + dp[j][k]%mod)%mod ;
        }
        
        dp[i][a[i]] += 1 ;
    }
        
    ll sum=0 ;    
    for(ll i=0; i<n; i++)
        sum = (sum%mod + dp[i][1]%mod)%mod ;
    
    cout << sum%mod << endl ;
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