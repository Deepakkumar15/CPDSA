// TOP DOWN DP APPROACH IMPLEMENTATION
// ITERATIVE DP CODE SOLUTION
// 01 KNAPSACK 2 PROBLEM
 
#include <bits/stdc++.h>
 
using namespace std ;
 
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
ll sum=0 ;
 
ll knapsack(vi &wt, vi &val, ll w, ll n){
    vector<vi> dp(105, vi (100005, 0));
    
    for(ll i=1; i<=sum; i++)
        dp[0][i] = 1e18;
        
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=sum; j++)
            val[i-1]<=j ? dp[i][j] = min(wt[i-1]+dp[i-1][j-val[i-1]], dp[i-1][j]) : dp[i][j] = dp[i-1][j] ;
       
    for(ll i=sum; i>=0; i--)
        if(dp[n][i]<=w)
            return i ;
            
    return 0 ;        
}
 
signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll n, w ;
    cin >> n >> w ;
    vi wt(n), val(n) ;
    for(int i=0; i<n; i++){
        cin >> wt[i] >> val[i] ;
        sum+=val[i] ;
    }
        
    cout << knapsack(wt, val, w, n) << endl ;
    
    return 0 ;
  
}