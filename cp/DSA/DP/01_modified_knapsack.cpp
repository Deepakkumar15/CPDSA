//GOOD PROBLEM ON CERTAIN MODIFICATION ON KNAPSACK DP
// HACKER EARTH BOB AND APPLES SOLUTION

#include <bits/stdc++.h>
 
using namespace std ;
 
// template for ordered_set 
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
 
const ll mod = 1e9+7 ;
const ll N = 1e5+7 ;
#define INF 1e9+7

void solve(){
	ll n, w ;
	cin >> n >> w ;
	vi val(n), wt(n) ;
	for(ll i=0; i<n; i++)
		cin >> val[i] >> wt[i] ;

	ll dp[n+1][w+1][2] ;
	for(ll i=0; i<=n; i++)
		for(ll j=0; j<=w; j++){
			dp[i][j][0] = 0 ;
			dp[i][j][1] = 0 ;
		}	

	for(ll i=1; i<=n; i++)
		for(ll j=1; j<=w; j++){
			if(wt[i-1]/2 <= j){ // can pick after doing the operation once
				dp[i][j][0] = max(val[i-1] + dp[i-1][j-(wt[i-1]/2)][1], dp[i-1][j][0]) ;
				if(wt[i-1] <= j){
					dp[i][j][0] = max(dp[i][j][0], val[i-1] + dp[i-1][j-wt[i-1]][0]) ;
					dp[i][j][1] = max(val[i-1] + dp[i-1][j-wt[i-1]][1], dp[i-1][j][1]) ;
				}

				else	
					dp[i][j][1] = dp[i-1][j][1] ;
				
			}	

			else{ // can't pick this weight in any of the way
				dp[i][j][0] = dp[i-1][j][0];
				dp[i][j][1] =  dp[i-1][j][1];
			}
		}	


	cout <<  max(dp[n][w][0], dp[n][w][1]) << endl ;
	return ;	
}

signed main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	ll t ;
	cin >> t ;
	while(t--)
		solve() ;
	return 0 ;
}