// ROTTEN ORANGES MULTISOURCE BFS

#include <bits/stdc++.h>
#define ll long long int
bool vis[15][15] = {false} ;
ll dx[] = {-1, 1, 0, 0} ;
ll dy[] = {0, 0, -1, 1} ;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ll n = grid.size() ;
        ll m = grid[0].size() ;
        ll ans=0 ;
        
        for(ll i=0; i<15; i++)
            for(ll j=0; j<15; j++)
                vis[i][j] = false ;
        
        queue<pair<ll, ll>> q ;
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++){
                if(grid[i][j] == 0 || grid[i][j] == 2) // make the empty and rotted cells visited
                    vis[i][j]=1 ;
                if(grid[i][j] == 2) // rotted cell -> make source
                    q.push({i, j}) ;
            }
        
        while(!q.empty()){
            ll k = q.size() ;
            while(k--){
                pair<ll, ll> p = q.front();
                q.pop() ;

                for(ll i=0; i<4; i++){
                    ll x = p.first + dx[i] ;
                    ll y = p.second + dy[i] ;

                    if(x >= n || x < 0 || y<0 || y>=m || vis[x][y])
                    continue ;
                    vis[x][y] = 1 ;
                    grid[x][y] = 2 ; // make it rotted
                    q.push({x, y}) ; // push in the queue
                }
            }
            
            if(!q.empty())
                ans++ ;
        }
        
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                if(grid[i][j] == 1)
                        return -1 ;
        
        return ans;
    }
};