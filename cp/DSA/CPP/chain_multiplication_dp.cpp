// MATRIX CHAIN MULTIPLICATION USING DP APPROACH
// PROGRAMME TO FIND OUT THE MINIMUM NUMBER OF 
// ITERATIONS REQUIRED TO MULTIPLY THE GIVEN 
// NUMBER OF MATRICES
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;

int dp[100][100] ;
int chain_multiplication(int matrix[], int i, int j)
{
	//base case
	if(i == j)
	{
		dp[i][j] = 0 ;	
		return 0 ;
	}
	
	// overlapping subproblems computation once	
	if(dp[i][j] != -1)
		return dp[i][j] ;

	int ans = INT_MAX ;

	for (int k = i; k < j; k++)
	{
		int temp = chain_multiplication(matrix, i, k) + chain_multiplication(matrix, k+1, j)
				 	+ matrix[i-1]*matrix[k]*matrix[j] ;
		ans = min(ans, temp) ;		
	}

	dp[i][j] = ans ; 
	return ans ;
}	

int main()
{
	// matrix array contains sizes of all matrices
	// matrix array contains matrix of sizes 
	// 1X2, 2X3, 3X4, 4X5, 5X6
	// chain multiplication of n matrices

	int n ;
	cout << "ENTER THE NUMBER OF MATRICES FOR CHAIN MULTIPLICATION : " ; 
	cin >> n ;
	int matrix[n+1] ; 
	// int n = sizeof(matrix)/sizeof(int) ;

	for (int i = 0; i <n; ++i)
	{
		cout << "ENTER THE ROW OF " << i+1 << " MATRIX : " ;
		int row ;
		cin >> row ;
		matrix[i] = row ;
		cout << "ENTER THE COLUMN OF " << i+1 << " MATRIX : " ;
		int col ;
		cin >> col ;
		if(i==n-1)
			matrix[i+1] = col ;
		cout << endl ;
	}

	// inserting -1 at each place of dp array
	memset(dp, -1, sizeof dp) ;
    
    // print number of iterations required to multiply chain of 5 matrices 
	cout << chain_multiplication(matrix, 1, n) ;
	return 0 ;

}	


