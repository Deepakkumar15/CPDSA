// BARCODE CODEFORCES SOLUTION
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
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
ll dxx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
ll dyy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

const ll mod = 1e9+7 ;
const ll N = 2e5+7 ;
#define INF 1e9+7

void solve(){
    ll n, m, x, y ;
    cin >> n >> m >> x >> y ;
    vs v ;
    for(ll i=0; i<n; i++){
        string s ;
        cin >> s ;
        v.push_back(s) ;
    }
    
    ll cnt[m+1][2] ;
    // cnt[i][0] -> how many ch to be required to make the whole column .
    // cnt[i][1] -> how many ch to be required to make the whole column #
    
    cnt[0][0] = cnt[0][1] = 0 ;
    
    for(ll i=0; i<m; i++){
        ll cnt1=0, cnt2=0 ;
        for(ll j=0; j<n; j++)
            v[j][i] == '.' ? cnt1++ : cnt2++ ;
        cnt[i+1][0] = cnt2 ;
        cnt[i+1][1] = cnt1 ;
    }
    
    // calculate the prefix sum on cnt array to make the bundles of that specific column
    for(ll i=1; i<=m; i++){
        cnt[i][0] += cnt[i-1][0] ;
        cnt[i][1] += cnt[i-1][1] ;
    }
    
    ll dp[m+1][2] ;
    for(ll i=0; i<=m; i++){
        dp[i][0] = INT_MAX ;
        dp[i][1] = INT_MAX ;
    }
    
    // dp[i][0] -> states that if we make the ith column . then min. ch required to change till now 
    // dp[i][1] -> states that if we make the ith column # then min. ch required to change till now
    dp[0][0] = dp[0][1] = 0 ;
    
    for(ll i=1; i<=m; i++)
        for(ll j=x; j<=y; j++)
            if(i-j>=0){
                dp[i][0] = min(dp[i][0], dp[i-j][1] + cnt[i][0] - cnt[i-j][0]) ;
                dp[i][1] = min(dp[i][1], dp[i-j][0] + cnt[i][1] - cnt[i-j][1]) ;
            }
            
    cout << min(dp[m][1], dp[m][0]) << endl ;    
    
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