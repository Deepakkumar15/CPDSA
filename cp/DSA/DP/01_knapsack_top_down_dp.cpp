// TOP DOWN DP APPROACH IMPLEMENTATION
// ITERATIVE DP CODE SOLUTION
// 01 KNAPSACK PROBLEM

#include <bits/stdc++.h>
 
using namespace std ;
#define ll long long int
 
ll knapsack(ll *wt, ll *val, ll w, ll n){
    ll dp[n+1][w+1] ;

    for(ll i=0; i<=n; i++)
        dp[i][0]=0 ;
    for(ll j=0; j<=w; j++)
        dp[0][j]=0 ;
        
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=w; j++){
            if(wt[i-1]<=j)
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]) ;
            else
                dp[i][j] = dp[i-1][j] ;
        }  
        
    return dp[n][w] ;    
}
 
signed main(){
  	ios_base::sync_with_stdio(false) ;
  	cin.tie(0) ;
  	cout.tie(0) ;
    
    ll n, w ;
    cin >> n >> w ;
    ll wt[n], val[n] ;
    for(int i=0; i<n; i++)
        cin >> wt[i] >> val[i] ;
        
    cout << knapsack(wt, val, w, n) << endl ;
    
	return 0 ;
  
}  










// UNBOUNDED KNAPSACK -> REPETITION OF ITEMS ARE ALLOWED.

for(ll i=0; i<=n; i++){
    for(ll j=0; j<=w; j++){
        if(i==0 || j==0) dp[i][j] = 0 ;
        else if(wt[i-1] <= j)
            dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]) ;
        else
            dp[i][j] = dp[i-1][j] ;
    }
}