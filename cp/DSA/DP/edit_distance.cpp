// EDIT DISTANCE:

// CONVERT STR1 INTO STR2 USING INSERT, DELETE, REPLACE OPERATIONS:
// FIND MIN. NUMBER OF OPERATION REQUIRED TO CONVERT STR1 -> STR2


// RECURSIVE FN 
void edit_dist(string a, string b, ll m, ll n){
	if(m==0) return n ; // if first string is empty, then we have to insert n char
						// to make both string equal
	if(n==0) return m ; // similar as above condition

	if(a[m] == b[n])	
		return edit_dist(a, b, m-1, n-1) ;

	else // if last char of both string are not matching, then try with all 3 operations
		return 1 + min(min(edit_dist(a, b, m, n-1)[insert], edit_dist(a, b, m-1, n)[delete]), 
						edit_dist(a, b, n-1,  m-1)[replace])
}




// DP SOLUTION:

vvi dp(m+1, vi (n+1)) ;

for(ll i=0; i<=m; i++){
	for(ll j=0; j<=n; j++){
		if(i==0) dp[i][j] = n ;
		else if(j==0) dp[i][j] = m ;
		else if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] ;
		else
			dp[i][j] = 1 + min(
						min(dp[i-1][j](delete), dp[i][j-1](insert)), dp[i-1][j-1](replace)) ;
	}
}

return dp[m][n] ;