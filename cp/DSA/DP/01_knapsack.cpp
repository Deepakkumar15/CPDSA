// 01 KNAPSACK DP PROBLEM
// RECURSION + MEMOIZATION SOLUTION
#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

ll dp[105][100005] ;

ll knapsack(ll *wt, ll *val, ll w, ll n){
        if(n==0 || w==0)
            return 0 ;
        if(dp[n][w]!=-1)
            return dp[n][w] ;
        if(wt[n-1]<=w)
            return dp[n][w]=max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1)) ;
        else
            return dp[n][w] = knapsack(wt, val, w, n-1) ;
}

signed main(){
  	ios_base::sync_with_stdio(false) ;
  	cin.tie(0) ;
  	cout.tie(0) ;
    
    memset(dp, -1, sizeof(dp)) ;
    ll n, w ;
    cin >> n >> w ;
    ll wt[n], val[n] ;
    for(int i=0; i<n; i++)
        cin >> wt[i] >> val[i] ;
        
    cout << knapsack(wt, val, w, n) << endl ;
    
	return 0 ;
  
}  