// NUMBER OF ISLANDS:
//CONNECTED COMPONENTS IN GRAPH

class Solution {
public:
    int ans=0 ;
    int parent[90025], size[90025];
    Solution(){
        // vector<int> parent(n+1), size(n+1, 0) ;
        for(int i=0; i<90025; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int find(int a){
        return parent[a] = (parent[a]==a ? a : find(parent[a])) ;
    }
    
    void Union(int a, int b){
        int pa = find(a) ;
        int pb = find(b) ;
        
        if(pa!=pb){
            if(size[pa] < size[pb])
                swap(pa, pb) ;
            
            parent[pb]=pa ;
            size[pa]+=size[pb] ;
        }
        
        return ;
    }
    
    int numIslands(vector<vector<char>>& grid){
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(j<m-1 && grid[i][j] == '1' && grid[i][j+1] == '1')
                    Union(i*m+j+1, i*m+j+2) ;
                if(i<n-1 && grid[i][j] == '1' && grid[i+1][j] == '1')
                    Union(i*m+j+1, i*m+j+m+1) ;
            }
        
        // CALCULATE TOTAL NUMBER OF CONNECTED COMPONENTS
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                int a = (i*m)+j+1 ;
                if(grid[i][j]=='1' && find(a)==a)
                    ans++ ;
            }
        
        return ans ;
            
    }
};






// GOOD PROBLEM ON CONNECTED COMPONENTS IN GRAPH
#define ll long long int
class Solution {
public:
    void dfs(vector<vector<char>> &grid, ll i, ll j, ll n, ll m){
        if(i<0 || j<0 || i>=n || j>=m)
            return ;
        if(grid[i][j] == '0')
            return ;
        
        grid[i][j] = '0' ; // mark the cell as visited by making it 0
        // now again recursively dfs to all 4 sides
        // we can use for loop as well for all 4 directions
        dfs(grid, i-1, j, n, m) ;
        dfs(grid, i+1, j, n, m) ;
        dfs(grid, i, j-1, n, m) ;
        dfs(grid, i, j+1, n, m) ;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // for connected components always loop for all nodes
        
        ll n = grid.size();
        ll m = grid[0].size() ;
        
        ll ans=0 ;
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, n, m) ;
                    ans++ ; // increase the count after finding the island
                }
        
        return ans ;
    }
};