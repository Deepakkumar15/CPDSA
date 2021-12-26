// k-ordered LCS HACKEREARTH SOLUTION

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
	ll n, m, t ;
	cin >> n >> m >> t ;
	vi a(n), b(m) ;
	for(ll i=0; i<n; i++)
		cin >> a[i] ;
	for(ll i=0; i<m; i++)
		cin >> b[i] ;	

	ll dp[n+1][m+1][t+1] ;
	for(ll i=0; i<=n; i++)
		for(ll j=0; j<=m; j++)
			for(ll k=0; k<=t; k++)
				(k>=i || k>=j) ? dp[i][j][k] = min(i, j) : dp[i][j][k]=0; ;

	for(ll i=1; i<=n; i++)
		for(ll j=1; j<=m; j++){
			if(a[i-1] == b[j-1]) // no requirement to use the operation
				for(ll k=0; k<=t; k++)
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]+1) ;
			else{
				dp[i][j][0] = max(dp[i][j][0], max(dp[i][j-1][0], dp[i-1][j][0])) ;
				for(ll k=1; k<=t; k++) // we have to exhaust one operation
					dp[i][j][k] = max(max(dp[i][j-1][k], dp[i-1][j][k]), (dp[i-1][j-1][k-1]+1)) ;
			}
		}
		
	cout << dp[n][m][t] << endl ;
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