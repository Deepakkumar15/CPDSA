#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;
#define N 10
int n ;

void printfun(int board[N][N])
{
	for(int i = 0 ; i < n ; ++i)
	{
	    for(int j = 0 ; j < n ; ++j )
        {   
            if(board[i][j] == 1)
                cout << "Q" << " " ;
            else
                cout << "_" << " " ;
        }
        cout << endl ;
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j ;
	for (i = 0 ; i < row ; i++)
		if(board[i][col] == 1)
			return false ;
    
   for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j] == 1) 
            return false; 
  
    for (i=row, j=col; i>=0 && j<N ; i--, j++) 
        if (board[i][j] == 1) 
            return false; 

return true ;

}

bool solveNQUEEN(int board[N][N], int row)
{
	if(row == n)
		return true ;
	
	for (int j = 0; j < n ; j++)
	{
		if(isSafe(board, row, j))
		{
			board[row][j] = 1 ;
			
			if(solveNQUEEN(board, row+1))
				return true ;
                
			board[row][j] = 0 ; // BACKTRACKING
		}	
	}

return false ;

}

int main()
{
	cin >> n ;

	int board[N][N] = {0} ;

	bool result = solveNQUEEN(board, 0) ;
	if(result)
		printfun(board) ;
	else
		cout << "Solution doesn't exist" ;

return 0 ;	
}









#define ll  int
#define vi  vector<ll>
#define vvi vector<vi>

class Solution{
public:
    ll grid[10][10] ;
    vvi ans ;
    Solution(){
        for(ll i=0; i<10; i++)
            for(ll j=0; j<10; j++)
                grid[i][j]=0 ;
    }
    bool isSafe(ll n, ll row, ll col){
        for(ll i=0; i<row; i++)
            if(grid[i][col] == 1)
                return false ;
        
        for(ll i=row, j=col; i>=0 && j>=0; i--, j--)
            if(grid[i][j] == 1)
                return false ;
        
        for(ll i=row, j=col; i>=0 && j<n; i--, j++)
            if(grid[i][j] == 1)
                return false ;
        return true ;
    }
    
    bool solve(ll n, ll row){
        if(row ==n){
            vi res ;
            for(ll i=0; i<n; i++)
                for(ll j=0; j<n; j++)
                    if(grid[i][j]==1)   
                        res.push_back(j+1) ;
                        
            ans.push_back(res) ;            
            return true ;
        }
        
        bool res = false ;    
        // now start iterating every row 
        for(ll i=0; i<n; i++)
            if(isSafe(n, row, i)){
                grid[row][i] = 1 ; // place the queen
                
                res = solve(n, row+1) || res ;
                
                grid[row][i] = 0 ; // backtrack
            }
            
        return res ;    
        
    }
    vector<vector<int>> nQueen(int n) {
        if(solve(n, 0))
            return ans ;
            
        return ans ;
    }
};
