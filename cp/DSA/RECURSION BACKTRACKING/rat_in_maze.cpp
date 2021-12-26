// RAT IN A MAZE
// BACKTRACKING QUESTION

#include <bits/stdc++.h>
#define ll int
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0}; 
class Solution{
    public:
    vector<string> ans ;
    int vis[5][5] ;
    Solution(){
        for(ll i=0; i<5; i++)
            for(ll j=0; j<5; j++)
                vis[i][j] = 0 ;
    }
    
    void solve(vector<vector<int>> &m, ll i, ll j, string path){
        ll n = m.size() ;
        if(i==n-1 && j==n-1){
            ans.push_back(path) ;
            return ;
        }

        string s = "DLRU" ;
        for(ll it=0; it<4; it++){
            ll x = i+dx[it] ;
            ll y = j+dy[it] ;
            
            if(x>=0 && y>=0 && x<n && y<n && m[x][y]==1 && vis[x][y] == 0){
                vis[i][j] = 1 ;    
                solve(m, x, y, path + s[it]);
                vis[i][j] = 0 ;
            }
        }
        
        return ;
    }
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(m[0][0]==1)        
            solve(m, 0, 0, "") ;        
      
        return ans ;
    }
};