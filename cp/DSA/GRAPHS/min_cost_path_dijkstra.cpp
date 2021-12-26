//  CALCULATE MIN. COST PATH FROM TOP LEFT TO BOTTOM RIGHT IN A MATRIX
// USING DIJKSTRA ALGORITHM AND WE CAN MOVE IN ALL FOUR DIRECTIONS
#include <bits/stdc++.h>
 
using namespace std ;
 
// template for ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class c, class cmp = less<c> > 
using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

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
ll row, col ;
vector<vi> dist ; // to store the min. distance from the given source node

// structure of a cell
class cell{
public:    
    ll x, y, distance ;
    cell(ll x1, ll y1, ll d){
        x = x1; 
        y = y1 ;
        distance = d ;
    }
};

// comparing function for two cells 
bool operator<(const cell &a, const cell &b){
    if(a.distance == b.distance){
        if(a.x != b.x)
            return a.x < b.x ;
        return a.y < b.y ;
    }
    
    return a.distance < b.distance ;
} 

// function for checking the point is inside the grid or not
bool insideGrid(ll i, ll j){
    return (i>=0 && i<row && j>=0 && j<col) ;
}

// return the min. cost to reach the right bottom from the top left
// MODIFIED DIJKSTRA CODE
ll dijkstra(vector<vi> &grid){
    // initialize the distance array
    for(ll i=0; i<row; i++){
        vi res(col, INT_MAX) ;
        dist.push_back(res) ;
    }
    
    // direction arrays
    ll dx[4] = {-1, 1, 0, 0} ;
    ll dy[4] = {0, 0, 1, -1} ;
    
    // initialize the set of cell 
    set<cell> s ;
    s.insert(cell(0, 0, 0)) ;
    
    dist[0][0] = grid[0][0] ;
    
    while(!s.empty()){
        cell res = *s.begin() ;
        s.erase(s.begin()) ;
        
        // now loop over all 4 neighbours
        for(ll i=0; i<4; i++){
            ll x = res.x + dx[i] ;
            ll y = res.y + dy[i] ;
            
            // if not inside the grid, then ignore them
            if(!insideGrid(x, y))
                continue ;
            // if we find the other min distance path, then update it
            if(dist[x][y] > dist[res.x][res.y] + grid[x][y]){
                if(dist[x][y] != INT_MAX)
                    s.erase(s.find(cell(x, y, dist[x][y]))) ;
                dist[x][y] = dist[res.x][res.y] + grid[x][y] ;
                s.insert(cell(x, y, dist[x][y])) ;
            }    
        }
    }
    
    return dist[row-1][col-1] ;
}

void solve(){
    cin >> row >> col ;
    vector<vi> grid ;
    for(ll i=0; i<row; i++){
        vi res ;
        for(ll j=0; j<col; j++){
            ll x ;
            cin >> x ;
            res.push_back(x) ;
        }
        grid.push_back(res) ;
    }
    
    cout << dijkstra(grid) << endl ;
    return ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll t=1;
    // cin >> t ;
    
    while(t--)
        solve() ;
    
    return 0 ;
} 