// using recursion + memoization method
// good dp and implementation 
// BASKETBALL EXERCISE (CODEFORCES)

#include <bits/stdc++.h>
 
using namespace std ;
 
#define ll  long long int
#define vi  vector<ll>
#define vs  vector<string>
#define vb  vector<bool>
#define pi  pair<ll, ll>
#define vpi vector<pi>
 
#define mod 1e9+7
#define INF 1e9+7
const ll N = 1e5+7 ;
ll dp[N][2], h[N][2], n ;

ll fn(ll i, ll j){
    if(i==n)
        return 0 ;
    if(dp[i][j]!=-1)
        return dp[i][j] ;
    if(j==0)
        return dp[i][j] = max(h[i][j]+fn(i+1, 1), fn(i+1, 0)) ;
        
    else
        return dp[i][j] = max(h[i][j]+fn(i+1, 0), fn(i+1, 1)) ;
}

void solve() {
	cin >> n ;
	for(ll i=0; i<2; i++)
	    for(ll j=0; j<n; j++)
	        cin >> h[j][i] ;
    memset(dp, -1, sizeof(dp)) ;
	
	cout << max(fn(0, 0), fn(0, 1)) << "\n" ; 
	return ;
}


signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t = 1;
    while(t--)
        solve() ;
        
    return 0 ;
}